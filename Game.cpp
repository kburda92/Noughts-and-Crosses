#include "Game.h"
#include <QDebug>
#include <algorithm>
#include "utils.h"

using namespace std;

//we must fill our board with empty values
Game::Game() : m_board {0}
{
}

bool Game::Mark(int fieldNumber, int player)
{
    if(fieldNumber < 0 || fieldNumber > 8)
        throw "field number must be between 0 and 8";
    if(player == 0)
        throw "player can't' mark field as empty";

    m_board[fieldNumber] = player;
    return IsAnyPlayerWinner();
}

bool Game::IsAnyPlayerWinner()
{
    for(auto& layout : m_winning_layouts)
    {
        //for every layout we create temporary array of 3 fields
        array<int, 3> temp_array;
        for(int i=0;i<3;i++)
            temp_array[i] = m_board.at(layout.at(i));

        if(ContainsValue(temp_array, 0))
            continue;

        if(equal(begin(temp_array)+1, end(temp_array), begin(temp_array)))
            return true;
    }

    return false;
}

int Game::IsBoardFull()
{
    return !ContainsValue(m_board, 0);
}

bool Game::IsSpaceEmpty(int index)
{
    return !m_board.at(index);
}
