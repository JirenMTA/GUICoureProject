#include "UsingLibrarys.h"
#include "WindowRead.h"
#include "WindowGetRight.h"
#include "WindowGrant.h"
#include "WindowListStorage.h"
class MainWindow : public QMainWindow{
Q_OBJECT

private:
    QPushButton *btnOpen;
    QPushButton *btnGrant;
    WindowRead* windowRead;
    WindowGetRight* windowGetRight;
    QPushButton *btnGetRight;
    WindowGrant *windowGrant;
    WindowListStorage* windowListStorage;
    QPushButton *btnListStorage;
    QLabel* labelID;
private slots:
    void handlerButton();
    void handlerGetRight();
    void handlerGrant();
    void handlerListStorage();

public:
    MainWindow(const QSize& maxBackgroundSize);

    MainWindow(const MainWindow&) = delete;

    MainWindow& operator=(const MainWindow&) = delete;
    ~MainWindow();

    void closeEvent(QCloseEvent *event);
};
