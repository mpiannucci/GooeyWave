#include <QApplication>
#include "gooeymain.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    GooeyMain* gooey = GooeyMain::getInstance();
    gooey->show();

    return a.exec();
    
    delete gooey;
}