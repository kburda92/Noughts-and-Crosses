import QtQuick 2.4

ResultForm {
    draws: gameEngine.result.draws
    player1Won: gameEngine.result.player1Won
    player2Won: gameEngine.result.player2Won
    player1Bold: gameEngine.actualPlayer == 1
    player2Bold: gameEngine.actualPlayer == 2
}
