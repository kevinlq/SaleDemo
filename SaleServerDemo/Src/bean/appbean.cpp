#include "appbean.h"

#include "tcpserverbean.h"

#include <QApplication>
#include <QThread>
#include <QDebug>

AppBean::AppBean(QObject *parent) :
    QObject(parent)
{
    init ();
}

AppBean::~AppBean()
{
}

void AppBean::init()
{
    m_pTcpBean = new TcpServerBean;
    m_pTcpThread = new QThread;
    m_pTcpBean->moveToThread (m_pTcpThread);

    connect (m_pTcpThread,SIGNAL(started()),
             m_pTcpBean,SLOT(slotStart()));
    connect (qApp,SIGNAL(aboutToQuit()),
             m_pTcpBean,SLOT(deleteLater()));
    connect (m_pTcpBean,SIGNAL(destroyed(QObject*)),
             m_pTcpThread,SLOT(quit()));
    connect (m_pTcpThread,SIGNAL(finished()),
             m_pTcpThread,SLOT(deleteLater()));

    connect (m_pTcpBean,SIGNAL(SignalClientConnect(int,QString,int)),
             this,SLOT(slotClientConnect(int,QString,int)));
    connect (m_pTcpBean,SIGNAL(SignalClientDisConnect(int,QString,int)),
             this,SLOT(slotClientDisConnect(int,QString,int)));
    connect (m_pTcpBean,SIGNAL(SignalClientReadData(int,QString,int,QByteArray)),
             this,SLOT(slotClientReadData(int,QString,int,QByteArray)));

    m_pTcpThread->start ();
}

void AppBean::slotClientReadData(int clientID, const QString &IP,
                                 int Port, const QByteArray &data)
{
    Q_UNUSED(clientID);

    QString str = QString("read data form ip:%1 port: %2 data:%3 ")
            .arg (IP).arg (Port).arg (QString(data));

    emit signalSendStr (str);
#if DEBUG_OUT
    qDebug()<<str;
#endif
}

void AppBean::slotClientConnect(int clientID, const QString &IP, int Port)
{
    Q_UNUSED(clientID);

    QString str = QString("client connect ip:%1 port: %2 ").arg (IP).arg (Port);

    emit signalSendStr (str);
#if DEBUG_OUT
    qDebug()<<str;
#endif
}

void AppBean::slotClientDisConnect(int clientID, const QString &IP, int Port)
{
    Q_UNUSED(clientID);

    QString str = QString("client disconnect ip:%1 port: %2 ").arg (IP).arg (Port);

    emit signalSendStr (str);
#if DEBUG_OUT
    qDebug()<<str;
#endif
}

