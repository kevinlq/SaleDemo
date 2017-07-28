#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

class QPushButton;
class QLineEdit;
class QComboBox;
class QLabel;
class QCheckBox;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private:
    void init();

    void initForm();

    void initWidget();

    void initConnect();

Q_SIGNALS:

private Q_SLOTS:
    void slotLoginClicked();

private:
    QLineEdit   *m_pLetName;
    QLineEdit   *m_pLetPwd;

    QLabel      *m_pLabelIcon;

    QCheckBox   *m_pCbxRemember;
    QCheckBox   *m_pCbxAutoLogin;

    QPushButton *m_pPbnRegister;
    QPushButton *m_pPbnForgon;
    QPushButton *m_pPbnLogin;

    QGridLayout *m_pGMainLayout;
};

#endif // LOGINWIDGET_H
