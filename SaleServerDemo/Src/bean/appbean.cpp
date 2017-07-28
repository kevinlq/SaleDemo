#include "appbean.h"

#include "tcpserverbean.h"

#include <QApplication>
#include <QThread>

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
    //
}

void AppBean::slotClientConnect(int clientID, const QString &IP, int Port)
{
    //
}

void AppBean::slotClientDisConnect(int clientID, const QString &IP, int Port)
{
    //
}

