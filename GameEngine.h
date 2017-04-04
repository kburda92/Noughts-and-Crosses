#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <array>
#include <QObject>
#include <memory>

class Game;
class GameEngine : public QObject
{
    Q_OBJECT

public:
    explicit GameEngine(QObject* parent = nullptr);
    ~GameEngine();
    unsigned int GetDraws();
    unsigned int GetResult(int playerNumer);
private:
    //m_results[0] - draws,
    //m_results[1] - number of player1 wins
    //m_results[2] - number of player2 wins
    std::array<int,3> m_results;
//    std::unique_ptr<Game> game;
public slots:
    void Move(int player);
};

#endif // GAMEENGINE_H
