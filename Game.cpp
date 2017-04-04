#include "Game.h"
#include <QDebug>
#include <algorithm>

using namespace std;

//we must fill our board with empty values
Game::Game() : m_actual_board {empty}
{
    MakeMove(0, cross);
}

void Game::MakeMove(int fieldNumber, FieldState state)
{
    if(fieldNumber < 0 || fieldNumber > 8)
        throw "field number must be between 0 and 8";

    int row = fieldNumber/3;
    int col = fieldNumber%3;
    m_actual_board[row][col] = state;
    CheckIsGameFinished();
}

void Game::CheckIsGameFinished()
{
    //for each case we create one dimension array and check if all fields have the same value (8 cases)

    //rows
    for(int i = 0;i < 3; ++i)
    {
        array<int, 3> partialArray = {m_actual_board[i][0], m_actual_board[i][1], m_actual_board[i][2]};
        if(equal(begin(partialArray) + 1, end(partialArray), begin(partialArray)))
            ;
    }

    //columns
    for(int i = 0;i < 3; ++i)
    {
        array<int, 3> partialArray = {m_actual_board[0][i], m_actual_board[1][i], m_actual_board[2][i]};
        if(equal(begin(partialArray) + 1, end(partialArray), begin(partialArray)))
            ;
    }


    //diagonally
    array<int, 3> partialArray1 = {m_actual_board[0][0], m_actual_board[1][1], m_actual_board[2][2]};
    array<int, 3> partialArray2 = {m_actual_board[0][2], m_actual_board[1][1], m_actual_board[2][0]};

    if(equal(begin(partialArray1) + 1, end(partialArray1), begin(partialArray1))
    || equal(begin(partialArray2) + 1, end(partialArray2), begin(partialArray2)))
        ;


}
