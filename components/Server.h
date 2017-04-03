#ifndef __SERVER_H__
#define __SERVER_H__

#include <QDialog>
#include <QLocalServer>

class Server : public QDialog {
	Q_OBJECT
public:
	Server(QString socket_path);
	~Server();
private:
	QLocalServer *server;
private slots:
	void read();
signals:
	void received_text(QString s);
};

#endif
