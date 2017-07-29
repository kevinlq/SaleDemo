#ifndef APPBEAN_H
#define APPBEAN_H

#include <QObject>

class TcpServerBean;

class QThread;

class AppBean : public QObject
{
    Q_OBJECT
public:
    explicit AppBean(QObject *parent = 0);
    ~AppBean();

private:
    void init();

Q_SIGNALS:
    void signalSendStr(const QString &str);

private Q_SLOTS:
    void slotClientReadData(int clientID,const QString &IP,
                            int Port,const QByteArray &data);

    void slotClientConnect(int clientID, const QString &IP,int Port);

    void slotClientDisConnect(int clientID,const QString &IP,int Port);

private:
    TcpServerBean   *m_pTcpBean;
    QThread         *m_pTcpThread;
};

#endif // APPBEAN_H
