#ifndef CLIENTSOCKETBEAN_H
#define CLIENTSOCKETBEAN_H

#include <QObject>
#include <QAbstractSocket>

class QTcpSocket;

struct socketInfo;

class ClientSocketBean : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocketBean(QObject *parent = 0);
    ~ClientSocketBean();

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:
    void slotStart();

    void slotReadServerData();

    void slotlSocetError(QAbstractSocket::SocketError);

    void slotWriteToSocket(const QString &str);

private:
    QTcpSocket  *m_pClientSocket;

    socketInfo  *d_ptr;
};

#endif // CLIENTSOCKETBEAN_H
