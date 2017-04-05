#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <array>
#include <QObject>
#include <memory>
#include <utils.h>

class Game;
class GameEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int draws READ draws WRITE setDraws NOTIFY drawsChanged)
    Q_PROPERTY(int player1Won READ player1Won WRITE setPlayer1Won NOTIFY player1Changed)
    Q_PROPERTY(int player2Won READ player2Won WRITE setPlayer2Won NOTIFY player2Changed)
public:
    explicit GameEngine(QObject* parent = nullptr);
    ~GameEngine();
    void setDraws(int);
    void setPlayer1Won(int);
    void setPlayer2Won(int);
    int draws() const;
    int player1Won() const;
    int player2Won() const;
private:
    //m_results[0] - draws,
    //m_results[1] - player1 wins
    //m_results[2] - player2 wins
    int m_draws = 0;
    int m_player1_won = 0;
    int m_player2_won = 0;
    std::unique_ptr<Game> game;
//    Player player1, player2;
    Figure m_figure = Figure::nought;
    void AddToResults(Figure);
public slots:
    void Move(int player);
signals:
    void drawsChanged();
    void player1Changed();
    void player2Changed();
};

#endif // GAMEENGINE_H
