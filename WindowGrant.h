//
// Created by hung on 08.03.23.
//

#ifndef TRYGUI_WINDOWGRANT_H
#define TRYGUI_WINDOWGRANT_H

#include "UsingLibrarys.h"

class WindowGrant: public QMainWindow {
    Q_OBJECT
private:
    QTextEdit* user;
    QTextEdit* file;
    QTextEdit* right;
    QPushButton* btn;
    
public:
    WindowGrant(QSize fixedSize);
    void AddBtnAndTb();
public slots:
    void setRight();  
};


#endif //TRYGUI_WINDOWGRANT_H
