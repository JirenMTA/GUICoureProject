//
// Created by hung on 07.03.23.
//

#include "WindowGetRight.h"

using namespace std;
WindowGetRight::WindowGetRight(QSize fixedSize) {
    this->setWindowTitle("Get right");
    this->setFixedSize(fixedSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);

    AddBtnAndTb();
}


void WindowGetRight::AddBtnAndTb()
{
    QWidget* widget = new QWidget(this);
    widget->setFixedSize(130, this->height());

    QWidget* widget2 = new QWidget(this);
    widget2->setFixedSize(this->width() - 130, this->height());
    widget2->setGeometry(140, 0, widget2->width(), widget2->height());

    btn = new QPushButton("Get right", widget);
    btn->setFixedSize(QSize(120, 30));
    connect(btn, &QPushButton::released, this, &WindowGetRight::handlerGetRight);




    QGridLayout* grid = new QGridLayout(widget);


    name = new QTextEdit(widget);
    name->setFixedSize(QSize(120, 30));

    file = new QTextEdit(widget);
    file->setFixedSize(QSize(120, 30));

    QLabel* labelName = new QLabel("Owner",   widget);
    QLabel* labelFileName = new QLabel("File name", widget);

    grid->addWidget(labelName, 0, 0);
    grid->addWidget(name, 1, 0);
    grid->addWidget(labelFileName, 2, 0);
    grid->addWidget(file, 3, 0);
    grid->addWidget(btn, 4, 0);
    widget->show();
    text = new QTextEdit(widget2);
    text->setFixedSize(widget2->size());
    widget2->show();
}

void WindowGetRight::handlerGetRight()
{
    string uid = name->toPlainText().toStdString();
    string filename = file->toPlainText().toStdString();
    stringstream right_in_stream;
    QMessageBox msgBox;
    try
    {
        right_t r = sec_check(std::stoi(uid), filename.c_str(), R_NONE);
        right_in_stream << r;
        text->setText(right_in_stream.str().c_str());
    }
    catch (const std::exception& ex)
    {
        msgBox.setText(QString("Error: ") + QString(ex.what()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}
