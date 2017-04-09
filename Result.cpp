#include "Result.h"

Result::Result(QObject* parent) : QObject(parent)
{
}

void Result::incDraws()
{
    m_draws++;
    emit drawsChanged();
}

int Result::draws() const
{
    return m_draws;
}


void Result::incPlayer1Won()
{
    m_player1_won++;
    emit player1Changed();
}

int Result::player1Won() const
{
    return m_player1_won;
}


void Result::incPlayer2Won()
{
    m_player2_won++;
    emit player2Changed();
}

int Result::player2Won() const
{
    return m_player2_won;
}




