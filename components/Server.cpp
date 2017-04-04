#include "Server.h"
#include <QDataStream>
#include <QLocalSocket>

Server::Server(QObject *parent, QString socket_path) {
	this->server = new QLocalServer(parent);
	if (!this->server->listen(socket_path)) {
		fprintf(stderr, "%s\n", qPrintable(server->errorString().toLatin1().constData()));
	}
	connect(this->server, SIGNAL(newConnection()), this, SLOT(read()));
}

Server::~Server() {
	this->server->close();
	delete this->server;
}

// read data from a socket connection until reaching a newline character
// emit signal "received_text(QString)" and pass the received data as text
void Server::read() {
	QLocalSocket *socket = this->server->nextPendingConnection();
	socket->waitForReadyRead();
	QByteArray in(socket->readLine());
	emit received_text(QString::fromLatin1(in.data()));
	socket->disconnectFromServer();
	delete socket;
}
