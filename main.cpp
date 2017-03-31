#include <QApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QQmlApplicationEngine engine(QUrl(QStringLiteral("qrc:/main.qml")));
	return app.exec();
}

