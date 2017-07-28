#include "mytcpserver.h"


Mytcpserver::Mytcpserver(QObject *parent)
    :QTcpServer(parent)
{

}

//指定客户端发送消息
void Mytcpserver::SendData(int clientID, QString IP, int Port, QByteArray data)
{
    Q_UNUSED(IP);
    Q_UNUSED(Port);

    for (int i = 0;i < ClientSocketID.count();i++)
    {
        if (ClientSocketID[i] == clientID)
        {
            ClientSocketList[i]->write(data);
            break;
        }
    }
}

void Mytcpserver::incomingConnection(int handle)
{
    Myclientsocket *client = new Myclientsocket(this,handle);
    client->setSocketDescriptor(handle);

    connect(client,SIGNAL(ClientReadData(int,QString,int,QByteArray)),this,SLOT(ReadData(int,QString,int,QByteArray)));
    connect(client,SIGNAL(ClientDisConnect(int,QString,int)),this,SLOT(DisConnect(int,QString,int)));

    emit ClientConnect(handle, client->peerAddress().toString(),client->peerPort());

    ClientSocketList.append(client);//将新的连接添加到列表
    ClientSocketID.append(handle);
}

void Mytcpserver::ReadData(int clientID, QString IP, int Port, QByteArray data)
{
    emit ClientReadData(clientID,IP,Port,data);
}

void Mytcpserver::DisConnect(int clientID, QString IP, int Port)
{
    for (int i = 0;i < ClientSocketID.count();i++)
    {
        if (ClientSocketID[i] == clientID)
        {
            ClientSocketList.removeAt(i);//从列表中移除该连接
            ClientSocketID.removeAt(i);
            emit ClientDisConnect(clientID,IP,Port);
            break;
        }
    }
}
