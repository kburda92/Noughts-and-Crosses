#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <QObject>
#include <memory>
#include "QQmlListProperty"

class Game;
class Result;
class GameEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int actualPlayer READ actualPlayer WRITE setActualPlayer NOTIFY actualPlayerChanged)
    Q_PROPERTY(QList<int> winnerSpaces READ winnerSpaces WRITE setWinnerSpaces NOTIFY winnerSpacesChanged)
    Q_PROPERTY(Result* result READ result CONSTANT)

public:
    explicit GameEngine(QObject* parent = nullptr);
    ~GameEngine();
    Result* result() const;
    QList<int> winnerSpaces() const;
    void setWinnerSpaces(const QList<int>&);
    int actualPlayer() const;
    void setActualPlayer(int);
    Q_INVOKABLE bool MarkSpace(int player);
    Q_INVOKABLE void StartNewGame();
private:
    std::unique_ptr<Game> game;
    int m_actual_player;
    QList<int> m_winner_spaces;
    Result* m_result;
    void ChangePlayer();
signals:
    void actualPlayerChanged();
    void winnerSpacesChanged();
};

#endif // GAMEENGINE_H
