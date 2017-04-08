#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <array>

//enum class Figure;
class Game
{
public:
    Game();
    bool Mark(int fieldNumber, int player);
    int IsBoardFull();
private:
    //board:
    //0   1   2
    //3   4   5
    //6   7   8
    std::array<int, 9> m_board;

    const std::array<std::array<int, 3>, 8> m_winning_layouts =
    {{
        //horizontally
        {{0, 1, 2}},
        {{3, 4, 5}},
        {{6, 7, 8}},
        //vertically
        {{0, 3, 6}},
        {{1, 4, 7}},
        {{2, 5, 8}},
        //diagonally
        {{0, 4, 8}},
        {{2, 4, 6}}
    }};
    bool IsAnyPlayerWinner();
};

#endif // GAME_H
