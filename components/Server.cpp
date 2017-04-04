#include "Server.h"
#include <QDataStream>
#include <QLocalSocket>

Server::Server(QString socket_path) {
	this->server = new QLocalServer();
	if (!this->server->listen(socket_path)) {
		qDebug("%s", server->errorString().toLatin1().constData());
	}
	connect(this->server, SIGNAL(newConnection()), this, SLOT(read()));
}

Server::~Server() {
	this->server->close();
}

// read data from a socket connection until reaching a newline character
// emit signal "received_text(QString)" and pass the received data as text
void Server::read() {
	QLocalSocket *socket = this->server->nextPendingConnection();
	socket->waitForReadyRead();
	QByteArray in(socket->readLine());
	emit received_text(QString::fromLatin1(in.data()));
	socket->disconnectFromServer();
}
