#include "config.h"

#include "util.h"

#include <QString>
#include <QStringList>
#include <QDebug>
#include <QVariant>
#include <QMap>
#include <QList>

Config::Config()
{
    m_pUtil = new Util;
}

Config::~Config()
{
    destroy();
}

void Config::setAppPath(const QString &path)
{
    m_pUtil->setConfigPath(path);
}

bool Config::loadDefaultInfo()
{
    QString path = m_pUtil->getConfigPath()+"/config/config.ini";
    return m_pUtil->checkConfigFile(path);
}

bool Config::emptyConfigFile()
{
    QString path = m_pUtil->getConfigPath()+"/config/config.ini";
    return m_pUtil->emptyConfigFile(path);
}

bool Config::writeInitfile(const QString &group,const QString &key,
                           const QVariant &value)
{
    QString path = m_pUtil->getConfigPath()+"/config/config.ini";
    return m_pUtil->writeInit(path,group,key,value);
}

bool Config::writeInitfile(const QString &group, const QVariantMap &params)
{
    QString path = m_pUtil->getConfigPath()+"/config/config.ini";
    for (QVariantMap::const_iterator i = params.constBegin();
         i != params.constEnd();i++)
    {
        if ( !m_pUtil->writeInit(path,group,i.key(),i.value()))
            return false;
    }
    return true;
}

void Config::destroy()
{
    if (m_pUtil){
        delete m_pUtil;
        m_pUtil = NULL;
    }

}

QString Config::getDatabaseType() const
{
    return m_pUtil->getString("database.type");
}

QString Config::getDatabaseHost() const
{
    return m_pUtil->getString("database.host");
}

QString Config::getDatabaseName() const
{
    return m_pUtil->getString("database.database_name");
}

QString Config::getDatabaseUsername() const
{
    return m_pUtil->getString("database.username");
}

QString Config::getDatabasePassword() const
{
    return m_pUtil->getString("database.password");
}

QString Config::getDatabaseTestOnBorrowSql() const
{
    return m_pUtil->getString("database.test_on_borrow");
}

bool Config::getDatabaseTestOnBorrow() const
{
    return m_pUtil->getBool("database.test_on_borrow");
}

int Config::getDatabaseMaxWaitTime() const
{
    return m_pUtil->getInt("database.max_wait_time");
}

int Config::getDatabaseMaxConnectionCount() const
{
    return m_pUtil->getInt("database.max_connection_count");
}

int Config::getDatabasePort() const
{
    return m_pUtil->getInt("database.port");
}

bool Config::isDatabaseDebug() const
{
    return m_pUtil->getBool("database.debug");
}

QString Config::getQssFiles() const
{
    return m_pUtil->getString("style.qss_files");
}

QString Config::getAppPath() const
{
    return m_pUtil->getString("app.appPath");
}

void Config::conTest()
{
    qDebug()<<"getDatabaseType:"<<getDatabaseType();
    qDebug()<<"getDatabaseHost:"<<getDatabaseHost();
    qDebug()<<"getDatabaseName:"<<getDatabaseName();
    qDebug()<<"getDatabaseUsername:"<<getDatabaseUsername();
    qDebug()<<"getDatabasePassword:"<<getDatabasePassword();
    qDebug()<<"getDatabaseTestOnBorrowSql:"<<getDatabaseTestOnBorrowSql();
    qDebug()<<"getDatabaseTestOnBorrow:"<<getDatabaseTestOnBorrow();
    qDebug()<<"getDatabaseMaxWaitTime:"<<getDatabaseMaxWaitTime();
    qDebug()<<"getDatabaseMaxConnectionCount:"<<getDatabaseMaxConnectionCount();
    qDebug()<<"getDatabasePort:"<<getDatabasePort();
    qDebug()<<"isDatabaseDebug:"<<isDatabaseDebug();
    qDebug()<<"getQssFiles:"<<getQssFiles();
}
