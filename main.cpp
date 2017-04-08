#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <memory>
#include "GameEngine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GameEngine gameEngine;
    engine.rootContext()->setContextProperty("gameEngine", &gameEngine);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
