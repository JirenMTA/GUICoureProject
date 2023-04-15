#include <QApplication>
#include "MainWindow.h"
#include "WindowLogin.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WindowLogin windowLogin(QSize(500, 300));
    windowLogin.show();

    //MainWindow mainWindow(QSize(500, 300));
    //mainWindow.show();

    return QApplication::exec();
}

//sudo xhost +si:localuser:user2
