#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <QDialog>
#include <QLocalSocket>

class Client : public QDialog {
	Q_OBJECT
public:
	Client(QLocalSocket *s);
private:
	QLocalSocket *socket;
private slots:
	void read_from_socket();
};

#endif
