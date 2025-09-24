#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include "ui/Logger.h"
#include "ui/RendererWindowModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
    
    engine.addImportPath("F:\\Qt\\Qt-6.9.1\\qml");
    QCoreApplication::setApplicationName("PointCloudViewer");
    QCoreApplication::setOrganizationName("FoxTold");

    qmlRegisterSingletonInstance("PointCloudViewer", 1, 0, "Logger", ui::Logger::instance().get());
    qmlRegisterType<GLViewport>("PointCloudViewer", 1, 0, "RendererWindowModel");
    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url, &engine](QObject *obj, const QUrl &objUrl)
        {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        auto* window = qobject_cast<QQuickWindow*>(engine.rootObjects()[0]);
        qDebug() << "Render interface" << window->rendererInterface()->graphicsApi();
     },
        Qt::QueuedConnection);
    
    engine.load(url);

    return app.exec();
}
