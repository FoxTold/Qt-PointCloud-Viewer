import QtQuick 2.6
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import PointCloudViewer 1.0
import OpenGLUnderQML

ApplicationWindow {
    id: root
    width: 1280
    height: 720
    minimumWidth: 1280
    minimumHeight: 720
    visible: true
    title: "Point Cloud Viewer"



    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        RowLayout {
            spacing: 0
            
            // RendererWindowModel {
            //     id: model
            //     Component.onCompleted: {
            //         Logger.info("RendererWindow Created")
            //     }
            // }
            Squircle{

            } 
            Rectangle {
                color: "blue"
                // Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.minimumWidth: 50
                Layout.preferredWidth: root.width * 0.3
            }
        }
        LogPanel{}
    }
}
