//
// Created by hung on 15.03.23.
//

#include "WindowRevoke.h"
//
// Created by hung on 08.03.23.
//

void WindowRevoke::AddBtnAndTb() {
    this->setWindowTitle("Rewoke");
    QWidget *widget = new QWidget(this);
    widget->setFixedSize(this->width(), this->height());

    btn = new QPushButton("Revoke right", widget);
    btn->setFixedSize(QSize(120, 30));
    connect(btn, &QPushButton::released, this, &WindowRevoke::revokeRight);

    QGridLayout *grid = new QGridLayout(widget);

    user = new QTextEdit(widget);
    user->setFixedSize(QSize(120, 30));

    file = new QTextEdit(widget);
    file->setFixedSize(QSize(120, 30));

    right = new QTextEdit(widget);
    right->setFixedSize(QSize(120, 30));

    QLabel *labelName = new QLabel("Revoke to user", widget);
    QLabel *labelFileName = new QLabel("File name", widget);
    QLabel *labelRight = new QLabel("Right", widget);

    labelFileName->setFixedSize(QSize(120,30));
    labelName->setFixedSize(QSize(120,30));
    labelRight->setFixedSize(QSize(120,30));

    grid->addWidget(labelName, 0 ,0);
    grid->addWidget(user, 1, 0);
    grid->addWidget(labelFileName, 2, 0);
    grid->addWidget(file, 3, 0);
    grid->addWidget(labelRight, 4, 0);
    grid->addWidget(right, 5,0);
    grid->addWidget(btn, 6,0);
}

WindowRevoke::WindowRevoke(QSize fixedSize) {
    this->setFixedSize(fixedSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);

    AddBtnAndTb();
}

void WindowRevoke::revokeRight() {
    QMessageBox msgBox;
    stringstream msgRight;
    try
    {
        int uid = std::stoi(user->toPlainText().toStdString());
        string filename = file->toPlainText().toStdString();
        right_t r = (right_t)(std::stoi(right->toPlainText().toStdString()));
        right_t received_r = sec_revoke(uid, filename.c_str(), r);
        msgRight << received_r;
        msgBox.setText((string("Got result rewoke-right: ") + msgRight.str()).c_str());
        msgBox.exec();
    }
    catch(std::invalid_argument const& ex){
        msgBox.setText(QString("Error  : ") + QString(ex.what()));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}






