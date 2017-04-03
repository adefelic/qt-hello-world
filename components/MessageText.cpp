#include "MessageText.h"

MessageText::MessageText(QObject *m) : message_text(m), timer(new QTimer()) {
	connect(this->timer, SIGNAL(timeout()), this, SLOT(clear_text()));
}

// replace the "text" property of a QObject with the text passed 
void MessageText::set_text(QString new_text) {
	this->message_text->setProperty("text", new_text);
	timer->start(5000);
}

void MessageText::clear_text() {
	this->message_text->setProperty("text", "");
}