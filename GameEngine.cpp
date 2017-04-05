#include "GameEngine.h"
#include "Game.h"
#include <QDebug>

using namespace std;

GameEngine::GameEngine(QObject* parent) : QObject(parent),
  game(make_unique<Game>())
{
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

void GameEngine::Move(int field)
{
    //if it was last empty field we know it's draw, we don't need to check it
    //if MakeMove return true we send signal to QML window about winner
    if(game->MakeMove(field, m_figure))
        AddToResults(m_figure);
    else if(game->GetNonEmptyFields() == 9)
        AddToResults(Figure::empty);

    m_figure = m_figure == Figure::cross ? Figure::nought : Figure::cross;
}

void GameEngine::AddToResults(Figure whoWon)
{
    //empty means it is draw
    switch((int)whoWon)
    {
    case 0: setDraws(draws() + 1);
        break;
    case 1: setPlayer1Won(player1Won() + 1);
        break;
    case 2: setPlayer1Won(player2Won() + 1);
        break;
    }

    game.reset();
}
