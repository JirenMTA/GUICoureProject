#include "MainWindow.h"

MainWindow::MainWindow(const QSize& maxBackgroundSize) {
    this->setFixedSize(maxBackgroundSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);


    QWidget* widget = new QWidget(this);
    widget->setFixedSize(this->size());

    labelID = new QLabel(widget);
    setuid(getuid());
    string uid_instr = to_string((int)(getuid()));
    labelID->setText(QString("USER ID: ") + QString(uid_instr.c_str()));
    labelID->setFixedSize(200, 50);

    btnOpen = new QPushButton("Open file", widget);
    btnOpen->setFixedSize(QSize(200, 50));
    connect(btnOpen, &QPushButton::released, this, &MainWindow::handleButton);

    btnGetRight = new QPushButton("Get right", widget);
    btnGetRight->setFixedSize(QSize(200, 50));
    connect(btnGetRight, &QPushButton::released, this, &MainWindow::handlerGetRight);

    btnGrant = new QPushButton("Grant right", widget);
    btnGrant->setFixedSize(QSize(200, 50));
    connect(btnGrant, &QPushButton::released, this, &MainWindow::handlerGrant);

    QGridLayout* grid = new QGridLayout(widget);

    grid->addWidget(labelID, 0, 0);
    grid->addWidget(btnOpen, 1, 0);
    grid->addWidget(btnGetRight, 2, 0);
    grid->addWidget(btnGrant, 3,0);

    widget->show();
    sec_init();
}

void MainWindow::handleButton() {
    WindowRead* windowRead = new WindowRead (QSize(400, 300));
    windowRead->show();
    //windowRead
    //windowRead;
}

 MainWindow::~MainWindow() noexcept {
    delete btnOpen;
    delete btnGetRight;
    delete this;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    windowRead->close();
    windowGetRight->close();
    windowGrant->close();
    delete windowRead;
}

void MainWindow::handlerGetRight() {
    windowGetRight= new WindowGetRight(QSize(400, 300));
    windowGetRight->show();
}

void MainWindow::handlerGrant() {
    windowGrant = new WindowGrant(QSize(400,300));
    windowGrant->show();;
}



















