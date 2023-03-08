//
// Created by hung on 07.03.23.
//

#ifndef TRYGUI_WINDOWGETRIGHT_H
#define TRYGUI_WINDOWGETRIGHT_H

#include "UsingLibrarys.h"

class WindowGetRight: public QWidget {
Q_OBJECT
public:
    WindowGetRight(QSize fixedSize);
    WindowGetRight(const WindowGetRight&) = delete;
    void AddBtnAndTb();
private:
    QPushButton* btn;
    QTextEdit* name;
    QTextEdit* file;
    QTextEdit* text;
private slots:
    void handlerGetRight();

};


#endif //TRYGUI_WINDOWREAD_H



#define TRYGUI_WINDOWGETRIGHT_H
