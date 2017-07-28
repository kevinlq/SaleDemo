#include <QApplication>

#include "ui/mainwidget.h"
#include "ui/login/loginwidget.h"

#include "util/config.h"
#include "db/ConnectionPool.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LoginWidget login;
    login.show ();

    int ret = app.exec();
    Singleton<ConnectionPool>::getInstance().destroy(); // 销毁连接池，释放数据库连接
    return ret;
}
