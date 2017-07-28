#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>

#include "myclientsocket.h"

class Mytcpserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit Mytcpserver(QObject *parent = 0);

    void SendData(int clientID,QString IP,int Port,QByteArray data);

private:
    QList<Myclientsocket *> ClientSocketList;
    QList<int> ClientSocketID;

protected:
    virtual void incomingConnection(int handle);

Q_SIGNALS:
    void ClientReadData(int clientID,QString IP,int Port,QByteArray data);

    void ClientConnect(int clientID,QString IP,int Port);

    void ClientDisConnect(int clientID,QString IP,int Port);

private Q_SLOTS:
    void ReadData(int clientID,QString IP,int Port,QByteArray data);

    void DisConnect(int clientID,QString IP,int Port);
};



#endif // MYTCPSERVER_H
