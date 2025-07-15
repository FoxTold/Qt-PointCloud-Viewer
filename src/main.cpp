#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ui/Logger.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.addImportPath("C:\\Qt\\Qt-6.9.1\\qml");
    QCoreApplication::setApplicationName("PointCloudViewer");
    QCoreApplication::setOrganizationName("FoxTold");

    qmlRegisterSingletonInstance("PointCloudViewer", 1, 0, "Logger", ui::Logger::instance().get());

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl)
        {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    
    engine.load(url);

    return app.exec();
}
