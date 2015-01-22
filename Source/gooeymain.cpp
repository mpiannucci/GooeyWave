#include "gooeymain.h"
#include "ui_gooeymain.h"

GooeyMain* GooeyMain::m_pInstance = NULL;

GooeyMain::GooeyMain(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::GooeyMain)
{
    // Set up the UI
    ui->setupUi(this);

    // Initialize the gui
    init();
}

GooeyMain::~GooeyMain() {
    delete ui;
}

GooeyMain* GooeyMain::getInstance() {
    if (m_pInstance == NULL) {
        m_pInstance = new GooeyMain();
    }
    return m_pInstance;
}

void GooeyMain::init() {
    
    createConnections();
}

void GooeyMain::createConnections() {
    
}