import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root
    width: 1280
    height: 720
    minimumWidth: 1280
    minimumHeight: 720
    visible: true

    RowLayout {
        anchors.fill: parent

        Rectangle {
            id: menuBar
            color: "tomato"
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.25
            Layout.maximumWidth: root.minimumWidth * 0.25
        }

        Rectangle {
            id: contentArea
            color: "lightblue"
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width - menuBar.width
        }
    }
}
