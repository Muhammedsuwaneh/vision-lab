import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts

Window {
    id: root
    width: 1300
    height: 880
    visible: true
    flags: Qt.FramelessWindowHint
    color: "transparent"

    Rectangle {
        id: appFrame
        anchors.fill: parent
        color: "#f8fafc"
        radius: 12
        clip: true

        GridLayout {
            anchors.fill: parent
            rows: 2
            rowSpacing: 0
            columnSpacing: 0

            // TITLE BAR
            TitleBar {
                id: titleBar
                Layout.row: 0
                Layout.fillWidth: true
                Layout.preferredHeight: 48
                z: 10
            }

            ColumnLayout
            {
                id: mainContent
                Layout.row: 1
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                z: 10
            }
        }
    }
}
