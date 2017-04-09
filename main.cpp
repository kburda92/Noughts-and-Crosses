#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "GameEngine.h"
#include "Result.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GameEngine gameEngine;

    qmlRegisterUncreatableType<Result>("result", 1, 0, "result", "");
    engine.rootContext()->setContextProperty("gameEngine", &gameEngine);
    engine.rootContext()->setContextProperty("result", gameEngine.result());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
