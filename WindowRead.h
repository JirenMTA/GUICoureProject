//
// Created by hung on 07.03.23.
//

#ifndef TRYGUI_WINDOWREAD_H
#define TRYGUI_WINDOWREAD_H
#include "UsingLibrarys.h"
class WindowRead: public QWidget {
Q_OBJECT
public:
    WindowRead(QSize fixedSize);
    WindowRead(const WindowRead&) = delete;
    void AddBtnAndTb();
private:
    QPushButton* btn;
    QTextEdit* name;
    QTextEdit* file;
    QTextEdit* text;
    QPushButton* setText;
private slots:
    void getDataOfFile();
    void setTextHandler();
};


#endif //TRYGUI_WINDOWREAD_H
