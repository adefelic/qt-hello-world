#include "Server.h"
#include "Client.h"
#include <QDataStream>
#include <QLocalSocket>

Server::Server(QString socket_path) {
	this->server = new QLocalServer();
	if (!this->server->listen(socket_path)) {
		qDebug("%s", server->errorString().toLatin1().constData());
	}
	connect(this->server, SIGNAL(newConnection()), this, SLOT(respond()));
}

// replace the "text" property of a QObject with the text passed 
void Server::respond() {
	qDebug() << "creating client";
	Client client(this->server->nextPendingConnection());
}
