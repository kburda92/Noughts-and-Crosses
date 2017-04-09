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
    Q_PROPERTY(Result* result READ result CONSTANT)

public:
    explicit GameEngine(QObject* parent = nullptr);
    ~GameEngine();
    Result* result() const;
    void setActualPlayer(int);
    int actualPlayer() const;
    Q_INVOKABLE bool MarkSpace(int player);
    Q_INVOKABLE void StartNewGame();
private:
    int m_actual_player = 0;
    std::unique_ptr<Game> game;
    Result* m_result;
    void ChangePlayer();
signals:
    void actualPlayerChanged();
};

#endif // GAMEENGINE_H
