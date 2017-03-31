#include <QApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	QCommandLineParser parser;
	parser.addPositionalArgument("path-to-socket", QCoreApplication::translate("main", "Path to socket"));
	parser.process(app);
	auto args = parser.positionalArguments();
	if (args.isEmpty()) {
		fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Must specify a socket")));
		return 1; // there's probably a better way to do this
	}
	QString socket_path = parser.positionalArguments().at(0);
	QQmlApplicationEngine engine(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
