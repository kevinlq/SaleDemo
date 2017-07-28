#include "tcpserverbean.h"

#include "tcpserver/mytcpserver.h"
#include <QThread>
#include <QDebug>

TcpServerBean::TcpServerBean(QObject *parent)
    : QObject(parent)
{
    init ();
}

TcpServerBean::~TcpServerBean()
{
}

void TcpServerBean::init()
{
}


void TcpServerBean::slotStart()
{
    qDebug()<<"tcp server thread id:"<<QThread::currentThreadId ();

    m_pTcpServer = new Mytcpserver(this);
    m_pTcpServer->listen (QHostAddress::Any,9999);

    connect (m_pTcpServer,SIGNAL(ClientConnect(int,QString,int)),
             this,SIGNAL(SignalClientConnect(int,QString,int)));
    connect (m_pTcpServer,SIGNAL(ClientDisConnect(int,QString,int)),
             this,SIGNAL(SignalClientDisConnect(int,QString,int)));
    connect (m_pTcpServer,SIGNAL(ClientReadData(int,QString,int,QByteArray)),
             this,SIGNAL(SignalClientReadData(int,QString,int,QByteArray)));
}
