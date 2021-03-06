#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <array>

//enum class Figure;
class Game
{
public:
    Game();
    bool Mark(int space, int player);
    int isBoardFull();
    bool isSpaceEmpty(int index);
    QList<int> winnerSpaces();
private:
    //board indexes:
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
    bool isAnyPlayerWinner();
    QList<int> m_winner_spaces;
};

#endif // GAME_H
