#include "ui/mainwidget.h"
#include <QApplication>

#include "util/config.h"
#include "db/ConnectionPool.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWidget w;
    w.show();

    int ret = app.exec();
    Singleton<ConnectionPool>::getInstance().destroy(); // 销毁连接池，释放数据库连接
    return ret;
}
