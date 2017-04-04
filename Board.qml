import QtQuick 2.0

Item {
    id: boardForm
    objectName: "BoardForm"
    property int player: 1
    Component {
        id: delegate
        Rectangle {
            id: rect

            border.color: "black"
            border.width: 2
            width: parent.width/3
            height: parent.height/3

            Text {
                text: index
            }
            MouseArea{
                anchors.fill: parent
                onClicked:
                {
                    if(player == 1)
                        player = 2;
                    else
                        player = 1;
                    boardForm.move(index);
                }
            }
        }
    }

    GridView {
        id: grid
        interactive: false
        anchors.fill: parent
        height: parent.height
        width: parent.width
        cellHeight: height/3
        cellWidth: width/3
        model: 9
        delegate: delegate        
    }

    signal move(int fieldNumber)
}
