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

// replace the "text" property of a QObject with the text passed 
void Server::read() {
	QLocalSocket *socket = this->server->nextPendingConnection();
	socket->waitForReadyRead();
	QByteArray in(socket->readLine());
	emit received_text(QString::fromLatin1(in.data()));
	socket->disconnectFromServer();
}
