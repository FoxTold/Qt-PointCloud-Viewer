import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import PointCloudViewer 1.0

ScrollView {
    id: view
    Layout.preferredHeight: root.height * 0.2
    Layout.fillWidth: true

    TextArea {
        id: logArea
        readOnly: true
        wrapMode: TextArea.Wrap
        font.pixelSize: 16
    }

    Component.onCompleted: {
        Logger.newLogMessage.connect(function (msg) {
            logArea.append(msg);
        });
    }
}
