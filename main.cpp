#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <memory>
#include "GameEngine.h"
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GameEngine gameEngine;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto roots = engine.rootObjects();
    QObject* board = engine.rootObjects().at(0)->findChild<QObject*>("BoardForm");
    QObject::connect(board,
                     SIGNAL(move(int)),
                     &gameEngine,
                     SLOT(Move(int)));

    return app.exec();
}
