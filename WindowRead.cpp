//
// Created by hung on 07.03.23.
//

#include "WindowRead.h"

using namespace std;
WindowRead::WindowRead(QSize fixedSize) {
    this->setWindowTitle("Open file");
    this->setFixedSize(fixedSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
    
    AddBtnAndTb();
}


void WindowRead::AddBtnAndTb()
{
    QWidget* widget = new QWidget(this);
    widget->setFixedSize(130, this->height());

    QWidget* widget2 = new QWidget(this);
    widget2->setFixedSize(this->width() - 130, this->height());
    widget2->setGeometry(140, 0, widget2->width(), widget2->height());

    btn = new QPushButton("Read file", widget);
    btn->setFixedSize(QSize(120, 30));
    connect(btn, &QPushButton::released, this, &WindowRead::getDataOfFile);

    setText = new QPushButton("Set text", widget);
    setText->setFixedSize(QSize(120, 30));
    connect(setText, &QPushButton::released, this, &WindowRead::setTextHandler);

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
    grid->addWidget(setText, 5, 0);
    widget->show();
    text = new QTextEdit(widget2);
    text->setFixedSize(widget2->size());
    widget2->show();
}

void WindowRead::getDataOfFile()
{
    string uid = name->toPlainText().toStdString();
    string filename = file->toPlainText().toStdString();
    char short_text[64];

    QMessageBox msgBox;
    try
    {
	    int receivedFd = sec_openat(std::stoi(uid), filename.c_str(), 0x777);
	    if (receivedFd < 0)
	    {
	    	msgBox.setText("Error open file!");
            msgBox.exec();
	    }
	    else
	    {
            read(receivedFd, short_text, sizeof(short_text));
            text->setText(short_text);
	    }
    }
    catch (const std::exception& ex)
    {
    	msgBox.setText(QString("Error: ") + QString(ex.what()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void WindowRead::setTextHandler() {
    string uid = name->toPlainText().toStdString();
    string filename = file->toPlainText().toStdString();
    QMessageBox msgBox;
    try
    {
        int receivedFd = sec_openat(std::stoi(uid), filename.c_str(), 0x777);
        if (receivedFd < 0)
        {
            msgBox.setText("Error open file!");
            msgBox.exec();
        }
        else
        {
            if( write(receivedFd, text->toPlainText().toStdString().c_str(), sizeof(text->toPlainText().toStdString())) < 0)
                throw  std::invalid_argument("No permission to write");
        }
    }
    catch (const std::exception& ex)
    {
        msgBox.setText(QString("Error: ") + QString(ex.what()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}










