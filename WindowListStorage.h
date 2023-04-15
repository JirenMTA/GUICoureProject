//
// Created by hung on 10.03.23.
//

#ifndef TRYGUI_WINDOWLISTSTORAGE_H
#define TRYGUI_WINDOWLISTSTORAGE_H
#include "UsingLibrarys.h"

class WindowListStorage: public QWidget {
    Q_OBJECT
public:
    WindowListStorage(QSize fixedSize);
    WindowListStorage(const WindowListStorage&) = delete;
    void AddBtnAndTb();
private:
    QPushButton* btn;
    QTextEdit* name;
    QTextEdit* listStorageText;
private slots:
    void getListStorage();
};


#endif //TRYGUI_WINDOWLISTSTORAGE_H
