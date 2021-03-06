import QtQuick 2.4
import QtQuick.Controls 2.0


Item {
    width: 160
    height: 360

    property alias draws: drawsValue.text
    property alias player1Won: player1WonValue.text
    property alias player2Won: player2WonValue.text
    property alias player1Bold: player1WonText.font.bold
    property alias player2Bold: player2WonText.font.bold
    property alias startButton: startButton
    property alias lastResult: lastResult

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Column {
            id: column
            spacing: 5
            anchors.fill: parent


            Text {
                id: resultText
                text: qsTr("Result:")
                font.bold: true
                font.pixelSize: 25
            }



            Row {
                id: drawsRow
                width: 120
                height: 25
                transformOrigin: Item.Center
                clip: false
                spacing: 15

                Text {
                    id: drawsText
                    y: 0
                    text: qsTr("Draws:")
                    font.pixelSize: 20
                }

                Text {
                    id: drawsValue
                    x: 0
                    text: qsTr("0")
                    font.pixelSize: 20
                }
            }

            Row {
                id: player1WonRow
                width: 120
                height: 25
                spacing: 5

                Text {
                    id: player1WonText
                    y: 0
                    text: qsTr("Player1 (X):")
                    font.pixelSize: 20
                }

                Text {
                    id: player1WonValue
                    x: 0
                    text: qsTr("0")
                    font.pixelSize: 20
                }
            }

            Row {
                id: player2WonRow
                width: 120
                height: 25
                spacing: 5

                Text {
                    id: player2WonText
                    y: 0
                    text: qsTr("Player2 (O):")
                    font.pixelSize: 20
                }

                Text {
                    id: player2WonValue
                    x: 0
                    text: qsTr("0")
                    font.pixelSize: 20
                }
            }

            Button {
                id: startButton
                width: 90
                height: 25
                text: qsTr("Start game")
                enabled: true
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.right: parent.right
                anchors.rightMargin: 15
                visible: true
            }

        }



        Text {
            id: lastResult
            y: 181
            text: qsTr("Text")
            horizontalAlignment: Text.AlignHCenter
            anchors.right: parent.right
            anchors.rightMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            visible: false
            font.pixelSize: 16
        }
    }
}
