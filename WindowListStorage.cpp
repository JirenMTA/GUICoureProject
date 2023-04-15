//
// Created by hung on 10.03.23.
//

#include "WindowListStorage.h"
//
// Created by hung on 07.03.23.
//

#include "WindowListStorage.h"

using namespace std;
WindowListStorage::WindowListStorage(QSize fixedSize) {
    this->setWindowTitle("List storage");
    this->setFixedSize(fixedSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);

    AddBtnAndTb();
}


void WindowListStorage::AddBtnAndTb()
{
    QWidget* widget = new QWidget(this);
    widget->setFixedSize(130, this->height());

    QWidget* widget2 = new QWidget(this);
    widget2->setFixedSize(this->width() - 130, this->height());
    widget2->setGeometry(140, 0, widget2->width(), widget2->height());

    btn = new QPushButton("List storage", widget);
    btn->setFixedSize(QSize(120, 30));
    connect(btn, &QPushButton::released, this, &WindowListStorage::getListStorage);

    QGridLayout* grid = new QGridLayout(widget);

    name = new QTextEdit(widget);
    name->setFixedSize(QSize(120, 30));

    QLabel* labelName = new QLabel("Owner",   widget);
    labelName->setFixedSize(QSize(120,30));

    grid->addWidget(labelName, 0, 0);
    grid->addWidget(name, 1, 0);
    grid->addWidget(btn, 2, 0);
    widget->show();

    listStorageText = new QTextEdit(widget2);
    listStorageText->setFixedSize(widget2->size());
    widget2->show();
}

void WindowListStorage::getListStorage() {
    string uid = name->toPlainText().toStdString();
    stringstream listStream;
    QMessageBox msgBox;
    try
    {
        auto listResult = sec_list_storage(std::stoi(uid));
        listStream << listResult;
        listStorageText->setText(listStream.str().c_str());
    }
    catch (const std::exception& ex)
    {
        msgBox.setText(QString("Error: ") + QString(ex.what()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}










