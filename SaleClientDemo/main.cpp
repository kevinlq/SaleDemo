#include <QApplication>

#include "ui/mainwidget.h"
#include "ui/login/loginwidget.h"

#include "util/config.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LoginWidget login;
    login.show ();

    int ret = app.exec();

    return ret;
}
