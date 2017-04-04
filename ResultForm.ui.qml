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
                id: text1
                text: qsTr("Result:")
                font.bold: true
                font.pixelSize: 25
            }



            Row {
                id: row1
                width: 120
                height: 25
                transformOrigin: Item.Center
                clip: false
                spacing: 15

                Text {
                    id: text2
                    y: 0
                    text: qsTr("Draws:")
                    font.pixelSize: 20
                }

                Text {
                    id: draws
                    x: 0
                    text: qsTr("0")
                    font.pixelSize: 20
                }
            }

            Row {
                id: row2
                width: 120
                height: 25
                spacing: 5

                Text {
                    id: text3
                    y: 0
                    text: qsTr("Player1:")
                    font.pixelSize: 20
                }

                Text {
                    id: player1Won
                    x: 0
                    text: qsTr("0")
                    font.pixelSize: 20
                }
            }

            Row {
                id: row3
                width: 120
                height: 25
                spacing: 5

                Text {
                    id: text4
                    y: 0
                    text: qsTr("Player2:")
                    font.pixelSize: 20
                }

                Text {
                    id: player2Won
                    x: 0
                    text: qsTr("0")
                    font.pixelSize: 20
                }
            }

        }


    }
}
