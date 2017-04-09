#ifndef RESULT_H
#define RESULT_H

#include "QObject"

class Result : public QObject
{
    Q_OBJECT
    //we don't need write section, because we only use increment function which doesn't take any parameters
    Q_PROPERTY(int draws READ draws NOTIFY drawsChanged)
    Q_PROPERTY(int player1Won READ player1Won NOTIFY player1Changed)
    Q_PROPERTY(int player2Won READ player2Won NOTIFY player2Changed)
public:
    explicit Result(QObject* parent = nullptr);
    int draws() const;
    void incDraws();
    int player1Won() const;
    void incPlayer1Won();
    int player2Won() const;
    void incPlayer2Won();
private:
    int m_draws = 0;
    int m_player1_won = 0;
    int m_player2_won = 0;
signals:
    void drawsChanged();
    void player1Changed();
    void player2Changed();
};


#endif // RESULT_H
