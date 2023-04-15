//
// Created by hung on 23.03.23.
//

#include "WindowLogin.h"
#include "MainWindow.h"
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <shadow.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>

#ifdef DEBUG
#define DBG_PRINT(s) (s);
#else
#define DBG_PRINT(s) ;
#endif


void err_exit(const char *msg, int code) {
    perror(msg);
    exit(code);
}
WindowLogin::WindowLogin(QSize fixedSize)
{
    this->setWindowTitle("Login");
    this->setFixedSize(fixedSize);
    int width = this->frameGeometry().width();
    int height = this->frameGeometry().height();
    QDesktopWidget wid;
    int screenWidth = wid.width();
    int screenHeight = wid.height();
    this->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
    AddBtnAndTb();
}

void WindowLogin::AddBtnAndTb() {
    QWidget* widget = new QWidget(this);
    widget->setFixedSize(this->size());
    widget->setFixedHeight(300);
    QLabel* labelUID = new QLabel();
    setuid(getuid());
    string uid_instr = to_string((int)(getuid()));
    labelUID->setText(QString("USER ID: ") + QString(uid_instr.c_str()));
    labelUID->setFixedSize(200, 40);
    tbxLogin = new QLineEdit();
    tbxPassword = new QLineEdit();
    tbxPassword->setEchoMode(QLineEdit::Password);
    QLabel* labelLogin = new QLabel("Login");
    QLabel* labelPassword = new QLabel("Password");
    btnLogin = new QPushButton("Login");
    btnLogin->setFixedSize(QSize(200, 40));
    connect(btnLogin, &QPushButton::released, this, &WindowLogin::HandlerBtnLogin);

    QGridLayout* grid1 = new QGridLayout();
    grid1->addWidget(labelUID, 0, 0);
    grid1->addWidget(labelLogin, 1, 0,1,1);
    grid1->addWidget(tbxLogin, 1, 1,1,4);
    grid1->addWidget(labelPassword, 2, 0,1,1);
    grid1->addWidget(tbxPassword, 2, 1,1,4);
    grid1->setColumnStretch(0, 1);
    grid1->setColumnStretch(1, 2);

    QGridLayout* grid2 = new QGridLayout();
    grid2->addWidget(btnLogin, 0, 0);

    grid1->setColumnStretch(0, 1);
    grid2->setColumnStretch(0, 1);
    grid2->setRowMinimumHeight(0, grid1->rowMinimumHeight(0));
    grid2->setContentsMargins(0, -1, 0, 0);

    grid1->setColumnStretch(0, 1);
    grid2->setColumnStretch(0, 1);
    grid2->setRowMinimumHeight(0, grid1->rowMinimumHeight(0));
    grid2->setContentsMargins(0, -1, 0, 0);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(grid1);
    layout->addLayout(grid2);
    widget->setLayout(layout);

    widget->show();
}
struct pam_response *reply;

//function used to get user input
int function_conversation(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr)
{
    *resp = reply;
    return PAM_SUCCESS;
}
int pam_authenticate_my(const char *username, const char *password) {
    const struct pam_conv local_conversation = { function_conversation, NULL };
    pam_handle_t *local_auth_handle = NULL; // this gets set by pam_start

    int retval;

    // local_auth_handle gets set based on the service
    retval = pam_start("common-auth", username, &local_conversation, &local_auth_handle);

    if (retval != PAM_SUCCESS)
    {
        std::cout << "pam_start returned " << retval << std::endl;
        return 0;
    }

    reply = (struct pam_response *)malloc(sizeof(struct pam_response));

    // *** Get the password by any method, or maybe it was passed into this function.
    reply[0].resp = new char[256];
    strcpy(reply[0].resp, password);
    reply[0].resp_retcode = 0;
    retval = pam_authenticate(local_auth_handle, 0);

    if (retval != PAM_SUCCESS)
    {
        if (retval == PAM_AUTH_ERR)
        {
            std::cout << "Authentication failure." << std::endl;
        }
        else
        {
            std::cout << "pam_authenticate_my returned." << retval << std::endl;
        }
       return 0;
    }
    std::cout << "Authenticated." << std::endl;
    if (retval != PAM_SUCCESS)
    {
        std::cout << "pam_end returned " << retval << std::endl;
        return 0;
    }

    return 1;
}

void WindowLogin::HandlerBtnLogin() {
    string username = tbxLogin->text().toStdString();
    string password = tbxPassword->text().toStdString();
    if (pam_authenticate_my(username.c_str(), password.c_str())){
        this->close();
        setuid(1000);
        MainWindow* mainWindow = new MainWindow(QSize(500, 300));
        mainWindow->show();
    }
    //printf("%s\n", password);

}
