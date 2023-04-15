//
// Created by hung on 24.03.23.
//

#ifndef TRYGUI_WINDOWDELETE_H
#define TRYGUI_WINDOWDELETE_H

#include "UsingLibrarys.h"
class WindowDelete :public QMainWindow {
Q_OBJECT
private:
    QTextEdit *user;
    QTextEdit *file;
    QPushButton *btn;
public:
    WindowDelete(QSize fixedSize);

    void AddBtnAndTb();

public slots:

    void deleteFile();
};
#endif //TRYGUI_WINDOWDELETE_H