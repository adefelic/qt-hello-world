#include "MessageText.h"

MessageText::MessageText(QObject *m) : message_text(m), timer(new QTimer()) {
	// when an instance's timer reaches zero, clear text from the instance's MessageText
	connect(this->timer, SIGNAL(timeout()), this, SLOT(clear_text()));
}

// replace the "text" property of MessageText with the text passed 
void MessageText::set_text(QString new_text) {
	this->message_text->setProperty("text", new_text);
	timer->start(5000);
}

// replace the "text" property of MessageText with an empty string
void MessageText::clear_text() {
	this->message_text->setProperty("text", "");
}