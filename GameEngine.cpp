#include "GameEngine.h"
#include "Game.h"
#include <QDebug>

using namespace std;

GameEngine::GameEngine(QObject* parent) : QObject(parent)
  //, game(make_unique<Game>())
{
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

void GameEngine::Move(int player)
{
    qDebug()<<player;
}
