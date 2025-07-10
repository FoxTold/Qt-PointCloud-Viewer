#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.addImportPath("C:\\Qt\\Qt-6.9.1\\qml");
    // Load the QML file
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );

    engine.load(url);

    spdlog::info("Popciu to kozak");
    spdlog::info("Popciu to kozak");
    spdlog::info("Popciu to kozak");
    
    return app.exec();
}