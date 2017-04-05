#include "Game.h"
#include <QDebug>
#include <algorithm>
#include "utils.h"

using namespace std;

//we must fill our board with empty values
Game::Game() : m_actual_board {Figure::empty}
{
    //MakeMove(0, cross);
}

bool Game::MakeMove(int fieldNumber, Figure figure)
{
    if(fieldNumber < 0 || fieldNumber > 8)
        throw "field number must be between 0 and 8";
    if(figure == Figure::empty)
        throw "player can't' mark field as empty";

    int row = fieldNumber/3;
    int col = fieldNumber%3;

    if(m_actual_board[row][col] == Figure::empty)
    {
        m_actual_board[row][col] = figure;
        return CheckIsGameFinished();
    }
    return false;
}

bool Game::CheckIsGameFinished()
{
    //for each case we create one dimension array and check if the first field is not empty and
    //all fields have the same value (8 cases)

    ++m_non_empty_fields;

    //rows
    for(int i = 0;i < 3; ++i)
    {
        array<Figure, 3> partialArray = {m_actual_board[i][0], m_actual_board[i][1], m_actual_board[i][2]};
        if(partialArray.at(0) != Figure::empty &&
                equal(begin(partialArray) + 1, end(partialArray), begin(partialArray)))
            return true;
    }

    //columns
    for(int i = 0;i < 3; ++i)
    {
        array<Figure, 3> partialArray = {m_actual_board[0][i], m_actual_board[1][i], m_actual_board[2][i]};
        if(partialArray.at(0) != Figure::empty &&
                equal(begin(partialArray) + 1, end(partialArray), begin(partialArray)))
            return true;
    }

    //diagonally
    array<Figure, 3> partialArray1 = {m_actual_board[0][0], m_actual_board[1][1], m_actual_board[2][2]};
    array<Figure, 3> partialArray2 = {m_actual_board[0][2], m_actual_board[1][1], m_actual_board[2][0]};

    if((partialArray1 .at(0) != Figure::empty && equal(begin(partialArray1) + 1, end(partialArray1), begin(partialArray1)))
    && (partialArray2 .at(0) != Figure::empty && equal(begin(partialArray2) + 1, end(partialArray2), begin(partialArray2))))
        return true;

    return false;
}

int Game::GetNonEmptyFields()
{
    return m_non_empty_fields;
}
