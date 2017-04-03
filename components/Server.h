#ifndef __SERVER_H__
#define __SERVER_H__

#include <QDialog>
#include <QLocalServer>

class Server : public QDialog {
	Q_OBJECT
public:
	Server(QString socket_path);
private:
	QLocalServer *server;
private slots:
	void respond();
};

#endif
