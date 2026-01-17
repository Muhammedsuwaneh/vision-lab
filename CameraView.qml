/*
 * Author - Muhammed Suwaneh
*/

import QtQuick

Item {
    id: root

    Rectangle {
        id: container
        width: parent.width
        height: parent.height - 20
        radius: 20
        color: "#000"

        Image {
            id: cameraView
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            cache: false
            opacity: VisionController.running ? 1.0 : 0.0
            source: VisionController.running ? "image://camera/live" : ""

            Connections {
                target: camera
                function onFrameChanged() {
                    if (VisionController.running)
                        cameraView.source = "image://camera/live?" + Date.now()
                }
            }
        }

        Text {
            anchors.centerIn: parent
            text: "Camera Off"
            color: "white"
            font.pixelSize: 22
            opacity: VisionController.running ? 0 : 1

            Behavior on opacity {
                NumberAnimation { duration: 250 }
            }
        }
    }
}
