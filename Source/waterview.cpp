#include "waterview.h"
#include <QtOpenGL>
#include <QtGui>

WaterView::WaterView(QGLFormat& format, QWidget* parent) :
    QGLWidget(format, parent)
{

}

WaterView::~WaterView() {
    
}

void WaterView::init() {
    
}

QSize WaterView::minimumSizeHint() const {
    return QSize(50, 50);
}

QSize WaterView::sizeHint() const {
    return QSize(400, 400);
}

void WaterView::createConnections() {
    
}

void WaterView::initializeGL() {
    qglClearColor(QColor(125, 125, 255));
}

void WaterView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WaterView::resizeGL(int width, int height) {
    
}

void WaterView::mousePressEvent(QMouseEvent *event) {
    
}

void WaterView::mouseMoveEvent(QMouseEvent *event) {
    
}
