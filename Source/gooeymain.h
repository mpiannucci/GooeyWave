#ifndef GOOEYMAIN_H
#define GOOEYMAIN_H

#include <QMainWindow>

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

    // Singleton instance
    static GooeyMain* m_pInstance;
    
    void createConnections(void);

signals:

private slots:

};

#endif // GOOEYMAIN_H