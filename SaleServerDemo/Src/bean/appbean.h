#ifndef APPBEAN_H
#define APPBEAN_H

#include <QObject>

class AppBean : public QObject
{
    Q_OBJECT
public:
    explicit AppBean(QObject *parent = 0);
    ~AppBean();

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
};

#endif // APPBEAN_H
