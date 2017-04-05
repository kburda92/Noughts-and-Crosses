#include "GameEngine.h"
#include "Game.h"
#include <QDebug>

using namespace std;

GameEngine::GameEngine(QObject* parent) : QObject(parent),
  game(make_unique<Game>())
{
    fill(begin(m_results), end(m_results), 0);
}

GameEngine::~GameEngine()
{}

unsigned int GameEngine::GetDraws()
{
    return m_results.at(0);
}

unsigned int GameEngine::GetResult(int playerNumber)
{
    if(playerNumber != 1 && playerNumber != 2)
        throw "Player number must be 1 or 2";
    return m_results.at(playerNumber);
}

void GameEngine::Move(int field)
{
    //if it was last empty field we know it's draw, we don't need to check it
    //if MakeMove return true we send signal to QML window about winner
    if(game->MakeMove(field, m_figure))
        AddToResults((int)m_figure);
    else if(game->GetNonEmptyFields() == 9)
        AddToResults((int)m_figure);

    m_figure = m_figure == Figure::cross ? Figure::nought : Figure::cross;
}

void GameEngine::AddToResults(Figure whoWon)
{
    //empty means it is draw
    ++m_results[(int)whoWon];
    game.reset(make_unique<Game>());
    //emit
}
