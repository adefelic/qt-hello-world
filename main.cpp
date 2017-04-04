#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QTimer>
#include <QCommandLineParser>
#include <memory>
#include "components/MessageText.h"
#include "components/Server.h"
#include "debug.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	// parse command line args
	// a path to a socket is required
	QCommandLineParser parser;
	parser.addPositionalArgument("path-to-socket", QCoreApplication::translate("main", "Path to socket"));
	parser.process(app);
	auto args = parser.positionalArguments();
	if (args.isEmpty()) {
		fprintf(stderr, "%s\n",
			qPrintable("Error: Must specify a socket in the form:\n./qt-hello-world path_to_socket"));
		return 1; // there could be a better way to exit before calling app.exec()
	}
	auto socket_path = parser.positionalArguments().at(0);

	// create QQuickView
	auto view = std::make_unique<QQuickView>(QUrl(QStringLiteral("qrc:/main.qml")));

	// connect the clear button to the text box
	QObject *clear_button = view->rootObject()->findChild<QQuickItem *>("button_clear");
	QObject *message_text = view->rootObject()->findChild<QQuickItem *>("message_text");
	MessageText text_handler(message_text);
	QObject::connect(
		clear_button, SIGNAL(clicked()),
		&text_handler, SLOT(clear_text()));

	// create a socket server at the path passed in arg1
	Server server(socket_path);

	// when the server receives a message, update the message_text
	QObject::connect(
		&server, SIGNAL(received_text(QString)),
		&text_handler, SLOT(set_text(QString)));

	view->show();
	return app.exec();
}


