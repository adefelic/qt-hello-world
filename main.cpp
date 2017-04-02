#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QCommandLineParser>
#include "ClearButton.h"
#include "debug.h"


// torn between QQmlApplicationEngine and QQuickView

// replace the text of "message_text" with the text passed 
void update_message_text(std::unique_ptr<QQuickView> &view, QString new_text = "") {
	QObject *message_text = view->rootObject()->findChild<QQuickItem *>("message_text");
	message_text->setProperty("text", new_text);
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	// parse command line
	// a path to a socket is required
	QCommandLineParser parser;
	parser.addPositionalArgument("path-to-socket", QCoreApplication::translate("main", "Path to socket"));
	parser.process(app);
	auto args = parser.positionalArguments();
	if (args.isEmpty()) {
		fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Must specify a socket in the form:\n./qt-hello-world path_to_socket")));
		return 1; // there's probably a better way to do this
	}
	auto socket_path = parser.positionalArguments().at(0);

	// create our QQuickView
	auto view = std::make_unique<QQuickView>(QUrl(QStringLiteral("qrc:/main.qml")));

	// connect the event handler "ClearButton" to the button itself
	QObject *clear_button = view->rootObject()->findChild<QQuickItem *>("button_clear");
	ClearButton clear_button_handler(view);
	// have the handler listen for the "clicked()"" signal
	QObject::connect(
		clear_button, SIGNAL(clicked()),
		&clear_button_handler, SLOT(clickedSlot()));

	// TODO: after_five_seconds(update_message_text());

	/* TODO:
	connection = connect(path-to-socket);
	while((in_message = connection.get()) !== '\n') {
		if (in_message) {
			update_message_text(in_message);
		}
	}
	*/
	view->show();
	return app.exec();
}


