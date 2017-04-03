#include "MessageText.h"

MessageText::MessageText(QObject *m) : message_text(m) {}

// replace the "text" property of a QObject with the text passed 
void MessageText::set_message_text(QString new_text) {
	this->message_text->setProperty("text", new_text);
}

void MessageText::clear_slot() {
	this->message_text->setProperty("text", "");
}
