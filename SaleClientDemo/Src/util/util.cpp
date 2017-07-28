#include "util.h"

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSettings>
#include <QFileInfo>
#include <QDebug>
#include <QApplication>


Util::Util()
{
    init();
}

Util::~Util()
{
}

QString Util::getConfigPath()
{
    return m_appPath;
}

void Util::setConfigPath(const QString &path)
{
    Q_ASSERT(path != "");
    if (m_appPath != path)
        m_appPath = path;
}


bool Util::writeInit(const QString &path, const QString &group,
                     const QString &key,const QVariant &value)
{
    if (path.isEmpty() | key.isEmpty())
        return false;

    QSettings set(path,QSettings::IniFormat);
    set.beginGroup(group);
    set.setValue(key,value);
    set.endGroup();

    return true;
}

bool Util::writeInit(const QString &path, const QString &group,
                     const QVariantMap &params)
{
    if (path.isEmpty ())
        return false;
    QSettings set(path,QSettings::IniFormat);
    set.beginGroup (group);
    for (QVariantMap::const_iterator i = params.constBegin ();
         i != params.constEnd ();i++){
        set.setValue (i.key (),i.value ());
    }
    set.endGroup ();

    return true;
}

bool Util::readInit(const QString &path,const QString &group,
                    const QString &key,QVariant &value)
{
    if (path.isEmpty() | key.isEmpty())
        return false;

    QSettings set(path,QSettings::IniFormat);
    set.beginGroup(group);

    value = set.value(key);
    set.endGroup();

    return true;
}

QString Util::getString(const QString &path)
{
    return getConfigValue(path).toString();
}

QStringList Util::getStringList(const QString &path)
{
    return getConfigValue (path).toStringList ();
}

int Util::getInt(const QString &path)
{
    return getConfigValue(path).toInt();
}

double Util::getDouble(const QString &path)
{
    return getConfigValue(path).toDouble();
}

float Util::getFloat(const QString &path)
{
    return getConfigValue(path).toFloat();
}

bool Util::getBool(const QString &path)
{
    return getConfigValue(path).toBool();
}

void Util::init()
{
    //    checkConfigFile("data/config.ini");
    //    CreateNewConFile();
}

void Util::CreateNewConFile(const QString &fileInfo)
{
    //写入默认信息
    //数据库的一些配置信息
    QVariantMap params;
    params["debug"]         = true;
    params["type"]          = "QSQLITE";
    params["host"]          = "127.0.0.1";
    params["port"]          = "3306";
    params["database_name"] = "aisrealdata.db";
    params["username"]      = "root";
    params["password"]      = "root";
    params["test_on_borrow"]= true;
    params["test_on_borrow_sql"] = "SELECT 1";
    params["max_wait_time"] = 5000;
    params["max_connection_count"] = 5;
    writeInit(fileInfo,"database",params);

    writeInit(fileInfo,"style","qss_files","style");

    //应用程序信息
    writeInit(fileInfo,"app","appPath",m_appPath);
}

bool Util::checkConfigFile(const QString &fileName)
{
    //这里的判断目前还不完善，因为如果新添加内容时就再无法创建了
    if (fileName.isEmpty())
        return false;

    QFileInfo info(fileName);
    if (!info.exists()){
        CreateNewConFile(fileName);
        return true;
    }
    return false;
}

bool Util::emptyConfigFile(const QString &fileName)
{
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        return file.remove();
    }
    return false;
}

QVariant Util::getConfigValue(const QString &path)
{
    Q_ASSERT(path != "");
    QVariant value;
    QStringList tokens = path.split(".");
    int size = tokens.size();
    if (size != 2)
        return QVariant();

    readInit(m_appPath+"/config/config.ini",tokens.at(0),tokens.at(1),value);

    return value;
}

