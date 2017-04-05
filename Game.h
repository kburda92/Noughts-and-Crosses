#ifndef GAME_H
#define GAME_H

#include <array>
enum class Figure;
class Game
{
public:
    Game();
    bool MakeMove(int fieldNumber, Figure state);
    int GetNonEmptyFields();
private:
    std::array<std::array<Figure, 3>, 3> m_actual_board;
    bool CheckIsGameFinished();
    int m_non_empty_fields = 0;

};

#endif // GAME_H
