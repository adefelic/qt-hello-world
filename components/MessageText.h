#ifndef __MESSAGETEXT_H__
#define __MESSAGETEXT_H__

#include <QObject>
#include <QQuickView>
#include <QQuickItem>

class MessageText : public QObject {
	Q_OBJECT
public:
	MessageText(QObject *m);
private:
	QObject *message_text;
	void set_message_text(QString new_text);
public slots:
	void clear_slot();
};

#endif