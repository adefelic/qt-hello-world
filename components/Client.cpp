#include "Client.h"
#include <QDataStream>
#include <QLocalSocket>

Client::Client(QLocalSocket *s) : socket(s) {
	connect(this->socket, SIGNAL(readyRead()), this, SLOT(read_from_socket()));
}

void Client::read_from_socket() {
	QDataStream in(this->socket);
	in.startTransaction();
	QString s;
	in >> s;
	qDebug() << s;
}
