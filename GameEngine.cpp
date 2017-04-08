#include "GameEngine.h"
#include "Game.h"
#include <QDebug>

using namespace std;

GameEngine::GameEngine(QObject* parent) : QObject(parent),
  game(make_unique<Game>())
{
    m_actual_player = 1;
}

GameEngine::~GameEngine()
{
}

void GameEngine::setDraws(int value)
{
    if(value != m_draws)
    {
        m_draws = value;
        emit drawsChanged();
    }
}

void GameEngine::setPlayer1Won(int value)
{
    if(value != m_player1_won)
    {
        m_player1_won = value;
        emit player1Changed();
    }
}

void GameEngine::setPlayer2Won(int value)
{
    if(value != m_player2_won)
    {
        m_player2_won = value;
        emit player2Changed();
    }
}

void GameEngine::setActualPlayer(int value)
{
    m_actual_player = value;
    emit actualPlayerChanged();
}

int GameEngine::draws() const
{
    return m_draws;
}

int GameEngine::player1Won() const
{
    return m_player1_won;
}

int GameEngine::player2Won() const
{
    return m_player2_won;
}

int GameEngine::actualPlayer() const
{
    return m_actual_player;
}

void GameEngine::Move(int field)
{
    //if MakeMove returns true we send signal to QML window about winner
    //if MakeMove returns false we must we must check is board full
    if(game->MakeMove(field, m_actual_player))
    {
        if(m_actual_player == 1)
            setPlayer1Won(m_player1_won + 1);
        else if(m_actual_player == 2)
            setPlayer1Won(m_player2_won + 1);
    }
    else if(game->GetNonEmptyFields() == 9)
        setDraws(m_draws + 1);

    ChangePlayer();
}

void GameEngine::ChangePlayer()
{
    if(m_actual_player == 1)
        setActualPlayer(2);
    else if(m_actual_player == 2)
        setActualPlayer(1);
}
