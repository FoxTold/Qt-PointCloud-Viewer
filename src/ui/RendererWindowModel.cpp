// GLViewport.cpp
#include "RendererWindowModel.h"
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>

QOpenGLFramebufferObject *GLRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    return new QOpenGLFramebufferObject(size, format);
}

void GLRenderer::render()
{
    glViewport(0, 0, framebufferObject()->width(), framebufferObject()->height());
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // red
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
