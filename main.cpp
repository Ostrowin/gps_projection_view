#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "readfile.h"
#include <QQuickView>
#include <QObject>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();

   ReadFile reader;
   context->setContextProperty("dataSet", &reader);
//   qmlRegisterType<ReadFile>("DataSet", 1, 0, "DataSet");


   engine.load(url);

   return app.exec();
}

