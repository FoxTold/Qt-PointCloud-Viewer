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
    title: "Point Cloud Viewer"

    ColumnLayout {
        id: mainLayout
        spacing: 0
        anchors.fill: parent

        RowLayout {
            id: topSection
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: root.height * 0.8
            spacing: 0

            Rectangle {
                visible: false
                id: menuBar
                color: "tomato"
                Layout.fillHeight: true
                Layout.preferredWidth: root.width * 0.25
            }

            Rectangle {
                id: contentArea
                color: "lightblue"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Button {
                    id: openMenuBarButton
                    text: "X"
                    anchors {
                        top: parent.top
                        left: parent.left
                    }
                    onClicked: {
                        // Placeholder for point cloud loading logic
                        logArea.text += ": Menu Bar " + menuBar.visible  +"\n";
                        menuBar.visible = !menuBar.visible;
                    }
                }
            }
        }

        TextArea {
            id: logArea
            Layout.fillWidth: true
            Layout.preferredHeight: root.height * 0.2
            readOnly: true
            text: "Log output will appear here."
            wrapMode: TextArea.Wrap
            font.family: "Courier New"
            font.pointSize: 10
            color: "black"
        }
    }
}
