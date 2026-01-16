import QtQuick

Item
{
    id: root

    Rectangle
    {
        width: parent.width
        height: parent.height - 20
        color: "#000"
        radius: 20

        Image {
            id: cameraView
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            cache: false
            source: "image://camera/live"

            Connections {
                target: camera
                function onFrameChanged() {
                    cameraView.source = "image://camera/live?" + Date.now()
                }
            }
        }
    }

}
