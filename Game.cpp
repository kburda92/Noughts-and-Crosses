#include "Game.h"
#include <QDebug>
#include <algorithm>
#include "utils.h"

using namespace std;

//we must fill our board with empty values
Game::Game() : m_actual_board {0}
{
    //MakeMove(0, cross);
}

bool Game::MakeMove(int fieldNumber, int figure)
{
    if(fieldNumber < 0 || fieldNumber > 8)
        throw "field number must be between 0 and 8";
    if(figure == 0)
        throw "player can't' mark field as empty";

    m_actual_board[fieldNumber] = figure;
    return CheckIsGameFinished();
}

bool Game::CheckIsGameFinished()
{
    ++m_non_empty_fields;

    for(auto& layout : m_winning_layouts)
    {
//        if(any_of(begin(layout), end(layout), 0))
//            continue;

//        if(all_of(begin(layout)+1, end(layout), begin(layout)))
//            return true;
    }

    return false;
}

int Game::GetNonEmptyFields()
{
    return m_non_empty_fields;
}
