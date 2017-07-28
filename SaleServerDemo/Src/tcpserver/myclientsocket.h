#ifndef MYCLIENTSOCKET_H
#define MYCLIENTSOCKET_H

#include <QTcpSocket>

class Myclientsocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Myclientsocket(QObject *parent = 0,int m_clientID = 0);
    ~Myclientsocket();

private:
    int m_clientID;           //客户端ID

Q_SIGNALS:
    void ClientReadData(int clientID,QString IP,int Port,QByteArray data);
    void ClientDisConnect(int clientID,QString IP,int Port);

private Q_SLOTS:
    void ReadData();
    void DisConnect();
};

#endif // MYCLIENTSOCKET_H
