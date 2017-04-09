import QtQuick 2.0

Item {
    id: boardForm
    enabled: false
    property int actualPlayer: gameEngine.actualPlayer
    property var winnerSpaces: gameEngine.winnerSpaces
    property var symbols: new Array(9)
    property var winnerLine



    onWinnerSpacesChanged:
    {
        if(winnerSpaces.length === 3)
        {
            //drawing winning line
            var figureSource = "WinnerLine.qml";
            var component = Qt.createComponent(figureSource);
            if (component.status === Component.Ready)
                winnerLine = component.createObject(boardForm);

            console.log(point1)
            console.log(point2)
            line.point1 = winnerSpaces[0];
            line.point2 = winnerSpaces[2];
            line.requestPaint();
        }
    }

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
                function loadMark() {
                    var figureSource = boardForm.actualPlayer == 1 ?
                                "Nought.qml" : "Cross.qml";
                    var component = Qt.createComponent(figureSource);
                    if (component.status === Component.Ready)
                        var symbol = component.createObject(field);
                        symbols[index] = symbol;
                }
                onClicked:
                {
                    //if index is empty MarkSpace return true and we can put mark on it
                    if(gameEngine.MarkSpace(index))
                        loadMark();
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
}
