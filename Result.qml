import QtQuick 2.4

ResultForm {
    draws: gameEngine.draws
    player1Won: gameEngine.player1Won
    player2Won: gameEngine.player2Won
    player1Bold: gameEngine.actualPlayer == 1
    player2Bold: gameEngine.actualPlayer == 2
}
