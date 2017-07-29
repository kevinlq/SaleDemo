#ifndef APPBEAN_H
#define APPBEAN_H

#include <QObject>

class ClientSocketBean;
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
    void signalSendToServer(const QString &str);
private Q_SLOTS:


private:
    ClientSocketBean    *m_pClientBean;
    QThread             *m_pClientThread;
};

#endif // APPBEAN_H
