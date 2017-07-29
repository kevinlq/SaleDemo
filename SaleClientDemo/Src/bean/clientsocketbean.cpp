#include "clientsocketbean.h"

#include <QTcpSocket>
#include <QThread>

struct socketInfo{
    QString Ip;
    int port;
};

ClientSocketBean::ClientSocketBean(QObject *parent)
    : QObject(parent)
{
    init ();
}

ClientSocketBean::~ClientSocketBean()
{
    if (d_ptr){
        delete d_ptr;
        d_ptr = NULL;
    }
}

void ClientSocketBean::init()
{
    d_ptr = new socketInfo;
    d_ptr->Ip = "127.0.0.1";
    d_ptr->port = 9999;
}

void ClientSocketBean::slotStart()
{
    qDebug()<<"client socket thread id:"<<QThread::currentThreadId ();

    m_pClientSocket = new QTcpSocket(this);
    m_pClientSocket->abort ();

    m_pClientSocket->connectToHost (d_ptr->Ip,d_ptr->port);
    if ( m_pClientSocket->waitForConnected (1000) ){

#if DEBUG_OUT
        qDebug()<<"connect server ok!";
#endif

        connect (m_pClientSocket,SIGNAL(readyRead()),
                 this,SLOT(slotReadServerData()));
        connect (m_pClientSocket,SIGNAL(error(QAbstractSocket::SocketError)),
                 this,SLOT(slotlSocetError(QAbstractSocket::SocketError)));
    }else{
#if DEBUG_OUT
        qDebug()<<"connect server failed!";
#endif
    }
}

void ClientSocketBean::slotReadServerData()
{
    //
}

void ClientSocketBean::slotlSocetError(QAbstractSocket::SocketError)
{
    //
}

void ClientSocketBean::slotWriteToSocket(const QString &str)
{
    //这里应该有一个判断是否建立连接的逻辑，再想想添加
    if (!str.isEmpty ())
        m_pClientSocket->write (str.toLatin1 ());
}
