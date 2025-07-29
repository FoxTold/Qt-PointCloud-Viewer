import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import PointCloudViewer 1.0
import Qt.labs.platform 1.1
ApplicationWindow {
    id: root
    width: 1280
    height: 720
    minimumWidth: 1280
    minimumHeight: 720
    visible: true
    title: "Point Cloud Viewer"

    FileDialog {
    id: fileDialog
    onAccepted: {
            console.log("Chosen:", fileDialog.files[0])
            PointCloudLoaderModel.loadPointCloudXYZ(fileDialog.files[0]);
    }
    }
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
                id: menuBar
                visible: false
                color: "tomato"
                Layout.fillHeight: true
                Layout.preferredWidth: root.width * 0.25
                Button{
                    text: "Load PointCloud XYZ"
                    onClicked: {
                        fileDialog.open()
                    }
                }
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
                        menuBar.visible = !menuBar.visible;
                    }
                }
            }
        }

        LogPanel {}
    }
}
