import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 480
    height: 360
    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height
    title: qsTr("Nought and Crosses")

    MainForm {
        anchors.fill: parent
    }

}
