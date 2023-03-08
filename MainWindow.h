#include "UsingLibrarys.h"
#include "WindowRead.h"
#include "WindowGetRight.h"
#include "WindowGrant.h"
class MainWindow : public QMainWindow{
Q_OBJECT

private:
    QPushButton *btnOpen;
    QPushButton *btnGrant;
    WindowRead* windowRead;
    WindowGetRight* windowGetRight;
    QPushButton *btnGetRight;
    WindowGrant *windowGrant;
    QLabel* labelID;
private slots:
    void handleButton();
    void handlerGetRight();
    void handlerGrant();

public:
    MainWindow(const QSize& maxBackgroundSize);

    MainWindow(const MainWindow&) = delete;

    MainWindow& operator=(const MainWindow&) = delete;
    ~MainWindow();

    void closeEvent(QCloseEvent *event);
};
