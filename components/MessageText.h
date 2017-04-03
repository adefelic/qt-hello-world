#ifndef __MESSAGETEXT_H__
#define __MESSAGETEXT_H__

#include <QObject>
#include <QQuickItem>
#include <QTimer>

class MessageText : public QObject {
	Q_OBJECT
public:
	MessageText(QObject *m);
private:
	QObject *message_text;
	QTimer *timer;
public slots:
	void set_text(QString new_text);
	void clear_text();
};

#endif