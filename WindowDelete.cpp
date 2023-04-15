//
// Created by hung on 24.03.23.
//

#include "WindowDelete.h"

void WindowDelete::AddBtnAndTb() {
    this->setWindowTitle("Delete");
    QWidget *widget = new QWidget(this);
    widget->setFixedSize(this->width(), this->height());

    btn = new QPushButton("Delete file", widget);
    btn->setFixedSize(QSize(120, 30));
    connect(btn, &QPushButton::released, this, &WindowDelete::deleteFile);

    QGridLayout *grid = new QGridLayout(widget);

    user = new QTextEdit(widget);
    user->setFixedSize(QSize(120, 30));

    file = new QTextEdit(widget);
    file->setFixedSize(QSize(120, 30));

    QLabel *labelName = new QLabel("Owner", widget);
    QLabel *labelFileName = new QLabel("File name", widget);

    labelFileName->setFixedSize(QSize(120,30));
    labelName->setFixedSize(QSize(120,30));

    grid->addWidget(labelName, 0 ,0);
    grid->addWidget(user, 1, 0);
    grid->addWidget(labelFileName, 2, 0);
    grid->addWidget(file, 3, 0);
    grid->addWidget(btn, 5,0);
}

WindowDelete::WindowDelete(QSize fixedSize) {
    this->setFixedSize(fixedSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);

    AddBtnAndTb();
}

void WindowDelete::deleteFile() {
    QMessageBox msgBox;
    stringstream msgRight;
    try
    {
        int uid = std::stoi(user->toPlainText().toStdString());
        string filename = file->toPlainText().toStdString();

        int res = sec_unlink_at(uid, filename.c_str());
        msgBox.setText((string("Got result delete: ") + to_string(res)).c_str());
        msgBox.exec();
    }
    catch(std::invalid_argument const& ex){
        msgBox.setText(QString("Error  : ") + QString(ex.what()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}






