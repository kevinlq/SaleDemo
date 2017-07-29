#include "appbean.h"

#include "clientsocketbean.h"
#include <QThread>
#include <QApplication>

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
    m_pClientBean = new ClientSocketBean;
    m_pClientThread = new QThread;
    m_pClientBean->moveToThread (m_pClientThread);
    connect (m_pClientThread,SIGNAL(started()),
             m_pClientBean,SLOT(slotStart()));
    connect (qApp,SIGNAL(aboutToQuit()),
             m_pClientBean,SLOT(deleteLater()));
    connect (m_pClientBean,SIGNAL(destroyed(QObject*)),
             m_pClientThread,SLOT(quit()));
    connect (m_pClientThread,SIGNAL(finished()),
             m_pClientThread,SLOT(deleteLater()));

    connect (this,SIGNAL(signalSendToServer(QString)),
             m_pClientBean,SLOT(slotWriteToSocket(QString)));

    m_pClientThread->start ();
}

