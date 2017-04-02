import QtQuick 2.3
import QtQuick.Controls 2.1

// discovered that this is a thing: http://doc.qt.io/qt-5/stylesheet-syntax.html

Rectangle {
	visible: true
	width: 600
	height: 480

	Rectangle {
		id: message_container
		color: "#ddddee"
		anchors.top: parent.top
		anchors.topMargin: 20
		anchors.horizontalCenter: parent.horizontalCenter
		width: 500
		height : 300
		Text {
			objectName: "message_text"
			id: message_text
			anchors.centerIn: parent
			text: "Hello, World!"
		}
	}

	Button {
		objectName: "button_clear"
		id: button_clear
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: message_container.bottom
		anchors.topMargin: 40
		text: qsTr("Clear")
		background: Rectangle {
			implicitWidth: 100
			implicitHeight: 40
	    color: button_clear.down ? "#d6d6d6" : "#f6f6f6"
	    border.color: "#26282a"
			radius: 6
		}
	}
}