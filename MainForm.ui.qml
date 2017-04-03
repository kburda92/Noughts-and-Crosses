import QtQuick 2.7

Rectangle {
    id: rectangle1

    width: 480
    height: 360

    ResultForm {
        id: resultForm1
        x: 310
        y: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }
}
