#ifndef GAME_H
#define GAME_H

#include <array>

enum FieldState
{
    empty,
    nought,
    cross
};

class Game
{
public:
    Game();
private:
    std::array<std::array<int, 3>, 3> m_actual_board;
    void MakeMove(int fieldNumber, FieldState state);
    void CheckIsGameFinished();
};

#endif // GAME_H
