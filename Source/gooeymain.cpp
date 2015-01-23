#include "gooeymain.h"
#include "ui_gooeymain.h"

GooeyMain* GooeyMain::m_pInstance = NULL;

GooeyMain::GooeyMain(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::GooeyMain)
{
    // Set up the UI
    ui->setupUi(this);
    
    // Initialize the gl context
    m_glFormat.setVersion(3, 3);
    m_glFormat.setProfile(QGLFormat::CoreProfile);
    m_glFormat.setSwapInterval(1);
    QGLFormat::setDefaultFormat(m_glFormat);

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
    this->setWindowTitle("GooeyGL");
    
    m_waterView = std::shared_ptr<WaterView>(new WaterView(m_glFormat, this));
    ui->mainVerticalLayout->addWidget(m_waterView.get());
    
    createConnections();
}

void GooeyMain::createConnections() {
    
}