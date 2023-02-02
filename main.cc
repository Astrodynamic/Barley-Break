#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "gameboard.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

//    GameBoard model;
    qmlRegisterType<GameBoard> ("Game", 1, 0, "GameBoardModel");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/TEST/components/Application.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}