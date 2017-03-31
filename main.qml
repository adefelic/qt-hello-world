import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
	visible: true
	title: qsTr("Hello World")
	width: 320
	height: 180
	Text {
		id: greeting
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter
		text: "Hello, World!"
	}
	Button {
		text: qsTr("Clear")
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: greeting.bottom
		anchors.topMargin: 10
	}
}
