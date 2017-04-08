import QtQuick 2.0

Item {
    id: boardForm
    objectName: "BoardForm"
    property int actualPlayer: gameEngine.actualPlayer
    Component {
        id: delegate
        Rectangle {
            id: rect

            border.color: "black"
            border.width: 2
            width: parent.width/3
            height: parent.height/3

            MouseArea{
                id: field
                anchors.fill: parent
                function setSign() {
                    var figureSource = boardForm.actualPlayer == 1 ?
                                "Nought.qml" : "Cross.qml";
                    var component = Qt.createComponent(figureSource);
                    if (component.status == Component.Ready)
                        var button = component.createObject(field);
                }
                onClicked:
                {
                   setSign();
                   gameEngine.Move(index);
                   field.enabled = false;
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
