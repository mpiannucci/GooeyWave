#ifndef GOOEYMAIN_H
#define GOOEYMAIN_H

#include <QMainWindow>
#include "waterview.h"

namespace Ui {
class GooeyMain;
}

class GooeyMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit GooeyMain(QWidget *parent = 0);
    ~GooeyMain();

    static GooeyMain* getInstance(void);
    
    void init(void);

private:
    Ui::GooeyMain* ui;
    QGLFormat m_glFormat;
    std::shared_ptr<WaterView> m_waterView;

    // Singleton instance
    static GooeyMain* m_pInstance;
    
    void createConnections(void);

signals:

private slots:

};

#endif // GOOEYMAIN_H