//
// Created by hung on 23.03.23.
//

#ifndef TRYGUI_WINDOWLOGIN_H
#define TRYGUI_WINDOWLOGIN_H

#include "UsingLibrarys.h"

class WindowLogin : public QMainWindow {
    Q_OBJECT
public:
    WindowLogin(QSize fixedSize);
    void AddBtnAndTb();
private:
    QLineEdit *tbxLogin;
    QLineEdit *tbxPassword;
    QPushButton *btnLogin;
private slots:
    void HandlerBtnLogin();
};

#endif //TRYGUI_WINDOWLOGIN_H
