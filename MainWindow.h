#include "UsingLibrarys.h"
#include "WindowRead.h"
#include "WindowGetRight.h"
#include "WindowGrant.h"
#include "WindowListStorage.h"
#include "WindowRevoke.h"
#include "WindowDelete.h"
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
    WindowRevoke* windowRevoke;
    QPushButton* btnRevoke;
    QLabel* labelID;
    QPushButton* btnDelete;
    WindowDelete* windowDelete;
private slots:
    void handlerButton();
    void handlerGetRight();
    void handlerGrant();
    void handlerListStorage();
    void handlerRevoke();
    void handlerDelete();
public:
    MainWindow(const QSize& maxBackgroundSize);
    ~MainWindow();

    //void closeEvent(QCloseEvent *event);
};
