//
// Created by hung on 15.03.23.
//

#ifndef TRYGUI_WINDOWREVOKE_H
#define TRYGUI_WINDOWREVOKE_H

#include "UsingLibrarys.h"
class WindowRevoke: public QMainWindow {
    Q_OBJECT
private:
    QTextEdit* user;
    QTextEdit* file;
    QTextEdit* right;
    QPushButton* btn;

public:
    WindowRevoke(QSize fixedSize);
    void AddBtnAndTb();
public slots:
    void revokeRight();
};



#endif //TRYGUI_WINDOWREVOKE_H
