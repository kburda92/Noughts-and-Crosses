import QtQuick 2.7

Rectangle {
    id: rectangle

    width: 480
    height: 360
    z: 1
    scale: 1

    property alias result: resultForm
    property alias board: boardForm

    Result {
        id: resultForm
        x: 310
        y: 0
        visible: true
        clip: false
        opacity: 1
        z: 10
        anchors.right: parent.right
    }

    Board {
        id: boardForm
        width: 360
        height: 360
        anchors.left: parent.left
        anchors.leftMargin: 0
        scale: 1.02
        visible: true
        clip: false
    }
}
