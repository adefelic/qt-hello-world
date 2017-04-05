#ifndef __SERVER_H__
#define __SERVER_H__

#include <QDialog>
#include <QLocalServer>

// this class instantiates a QLocalServer at the supplied path
// when the server receives a connection, 
//   it reads in text data and emits it via the signal "received_text(QString)"
class Server : public QDialog {
	Q_OBJECT
public:
	Server(QObject *parent, QString socket_path);
private:
	QLocalServer *server;
private slots:
	void read();
signals:
	void received_text(QString s);
};

#endif
