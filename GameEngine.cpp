#include "GameEngine.h"
#include "Game.h"
#include "Result.h"
#include "utils.h"
#include <QDebug>

using namespace std;

GameEngine::GameEngine(QObject* parent) : QObject(parent),
  game(make_unique<Game>()), m_result(new Result(this))
{
    m_actual_player = 1;
}

GameEngine::~GameEngine()
{
}

Result* GameEngine::result() const
{
    return m_result;
}

int GameEngine::actualPlayer() const
{
    return m_actual_player;
}

void GameEngine::setActualPlayer(int value)
{
    m_actual_player = value;
    emit actualPlayerChanged();
}

bool GameEngine::MarkSpace(int index)
{
    if(!game->IsSpaceEmpty(index))
        return false;
    //if MakeMove returns true we send signal to QML window about winner
    //if MakeMove returns false we must we must check is board full - then it is draw
    if(game->Mark(index, m_actual_player))
    {
        if(m_actual_player == 1)
            result()->incPlayer1Won();
        else if(m_actual_player == 2)
            result()->incPlayer2Won();
    }
    else if(game->IsBoardFull())
        result()->incDraws();

    ChangePlayer();
    return true;
}

void GameEngine::ChangePlayer()
{
    if(m_actual_player == 1)
        setActualPlayer(2);
    else if(m_actual_player == 2)
        setActualPlayer(1);
}

void GameEngine::StartNewGame()
{
    game.reset();
    game = make_unique<Game>();
}
