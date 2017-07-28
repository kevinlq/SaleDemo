#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class AppBean;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    void init();

    void initForm();

    void initWidget();

    void initBean();

    void initConnect();

Q_SIGNALS:

private Q_SLOTS:

private:
    AppBean *m_pAppbean;
};

#endif // MAINWIDGET_H
