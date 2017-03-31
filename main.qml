import QtQuick 2.3
import QtQuick.Controls 2.1

ApplicationWindow {
	visible: true
	title: qsTr("Hello World")
	width: 600
	height: 480

	Rectangle {
		color: "#ddddee"
		anchors.top: parent.top
		anchors.topMargin: 20
		anchors.horizontalCenter: parent.horizontalCenter
		id: message_box
		width: 500
		height : 300
		Text {
			id: message
			anchors.centerIn: parent
			text: "Hello, World!"
		}
	}


	Button {
		id: button_clear
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: message_box.bottom
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