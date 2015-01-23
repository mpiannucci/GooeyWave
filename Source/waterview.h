#ifndef WATERVIEW_H
#define WATERVIEW_H

#include <QGLWidget>

class WaterView : public QGLWidget {
    Q_OBJECT
    
  public:
    WaterView(QGLFormat& format, QWidget* parent = 0);
    ~WaterView(void);
    
    void init(void);
    
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    
  protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    
  private:
    void createConnections(void);
    
  signals:
    
  public slots:
    
};


#endif // WATERVIEW_H
