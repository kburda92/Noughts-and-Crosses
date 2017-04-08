#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <memory>
#include "GameEngine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GameEngine gameEngine;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gameEngine", &gameEngine);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    QObject* board = engine.rootObjects().at(0)->findChild<QObject*>("BoardForm");
//    QObject::connect(board,
//                     SIGNAL(move(int)),
//                     &gameEngine,
//                     SLOT(Move(int)));

    return app.exec();
}
