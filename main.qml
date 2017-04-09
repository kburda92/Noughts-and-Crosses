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

        result.startButton.onClicked:
        {
            for (var i = 0; i < board.symbols.length; i ++)
                board.symbols[i].destroy();
            board.symbols.splice(0, board.symbols.length);
            gameEngine.StartNewGame();
            result.startButton.visible = false;
        }

        result.onDrawsChanged:
        {
            result.startButton.visible = true;
        }
        result.onPlayer1WonChanged:
        {
            result.startButton.visible = true;
        }

        result.onPlayer2WonChanged:
        {
            result.startButton.visible = true;
        }
    }

}
