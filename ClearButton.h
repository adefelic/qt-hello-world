#ifndef __CLEARBUTTON_H__
#define __CLEARBUTTON_H__

#include <QObject>
#include <QQuickView>
#include <QQuickItem>

class ClearButton : public QObject {
	Q_OBJECT
public:
	ClearButton(std::unique_ptr<QQuickView> &v) : view(v){}
private:
	// not super into this, as view could be deleted before a ClearButton object
	std::unique_ptr<QQuickView> &view;
public slots:
	void clickedSlot() {
		// clear the "message_text" object of text
		// TODO: this was copied from update_message_text() and should be refactored
		QObject *message_text = view->rootObject()->findChild<QQuickItem *>("message_text");
		message_text->setProperty("text", "");
	}
};

#endif