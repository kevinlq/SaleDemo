#ifndef TCPSERVERBEAN_H
#define TCPSERVERBEAN_H

#include <QObject>

class Mytcpserver;

class TcpServerBean : public QObject
{
    Q_OBJECT
public:
    explicit TcpServerBean(QObject *parent = 0);
    ~TcpServerBean();

private:
    void init();

Q_SIGNALS:
    void SignalClientReadData(int clientID,const QString &IP,
                              int Port,const QByteArray &data);

    void SignalClientConnect(int clientID,const QString &IP,int Port);

    void SignalClientDisConnect(int clientID,const QString &IP,int Port);

private Q_SLOTS:
    void slotStart();

private:
    Mytcpserver *m_pTcpServer;
};

#endif // TCPSERVERBEAN_H
