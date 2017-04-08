#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <array>

//enum class Figure;
class Game
{
public:
    Game();
    bool MakeMove(int fieldNumber, int state);
    int GetNonEmptyFields();
private:
    //board:
    //0   1   2
    //3   4   5
    //6   7   8
    std::array<int, 9> m_actual_board;

    std::array<std::array<int, 3>, 8> m_winning_layouts =
    {{
        //horizontally
        {{0, 1, 2}},
        {{3, 4, 2}},
        {{6, 7, 2}},
        //vertically
        {{0, 3, 2}},
        {{1, 4, 2}},
        {{2, 5, 2}},
        //diagonally
        {{0, 4, 2}},
        {{2, 4, 2}}
   }};
    bool CheckIsGameFinished();
    int m_non_empty_fields = 0;

};

#endif // GAME_H
