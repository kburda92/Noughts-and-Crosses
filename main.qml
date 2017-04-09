import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 520
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
            {
                if(board.symbols[i] !== undefined)
                    board.symbols[i].destroy();
            }
            board.symbols.splice(0, board.symbols.length);
            gameEngine.StartNewGame();
            result.startButton.visible = false;
            result.winnerRowVisible = false;
            board.enabled = true;
        }

        board.onWinnerSpacesChanged:
        {
            if(result.draws !== "0" || result.player1Won !== "0" || result.player2Won !== "0")
            {
                result.winnerValue = board.actualPlayer == 1 ? "Player 1" : "Player 2";
                result.startButton.visible = true;
                result.winnerRowVisible = true;
                boardForm.enabled = true;
            }
        }
    }

}
