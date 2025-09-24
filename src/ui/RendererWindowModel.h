#pragma once
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class GLRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    GLRenderer() {
        qDebug() << "GLRenderer created";
    }
    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
};

class GLViewport : public QQuickFramebufferObject {
    Q_OBJECT
public:
    explicit GLViewport(QQuickItem *parent = nullptr) : QQuickFramebufferObject(parent) {
                qDebug() << "GLViewport created";
    }

    QQuickFramebufferObject::Renderer* createRenderer() const override { 
        qDebug() << "Create renderer called!";
        return new GLRenderer; 
    }
};
