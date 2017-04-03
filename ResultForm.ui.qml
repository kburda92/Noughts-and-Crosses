import QtQuick 2.4

Item {
    width: 120
    height: 360

    Rectangle {
        id: rectangle1
        color: "#ffffff"
        anchors.fill: parent

        Column {
            id: column1
            spacing: 5
            anchors.fill: parent

            Text {
                id: text3
                text: qsTr("Player2: 0")
                font.pixelSize: 20
            }

            Text {
                id: text2
                text: qsTr("Player1: 0")
                font.pixelSize: 20
            }

            Text {
                id: text1
                text: qsTr("Result:")
                font.bold: true
                font.pixelSize: 25
            }


        }


    }
}
