/****************************************************************************
**
** Year    		: 2017-07-28
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	: this is a login widget
** If you have any questions , please contact me
**
****************************************************************************/
#include "loginwidget.h"

#define WIDGET_WIDTH    380
#define WIDGET_HEIGHT   160

/**incldue Qt file*/
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include "bean/appbean.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
{
    init ();
}

LoginWidget::~LoginWidget()
{
}

void LoginWidget::init()
{
    initForm ();

    initWidget ();

    initBean ();

    initConnect ();
}

void LoginWidget::initForm()
{
    this->setWindowTitle ("login");

    this->setFixedSize (WIDGET_WIDTH,WIDGET_HEIGHT);
}

void LoginWidget::initWidget()
{
    //用户名和密码输入框
    m_pLetName = new QLineEdit(this);
    m_pLetName->setPlaceholderText (QStringLiteral("手机/邮箱"));

    m_pLetPwd = new QLineEdit(this);
    m_pLetPwd->setPlaceholderText (QStringLiteral("密码"));

    //头像
    m_pLabelIcon = new QLabel(this);

    QPixmap pixmap(":/Images/login/login_icon.png");
    m_pLabelIcon->setFixedSize (90,90);
    m_pLabelIcon->setPixmap (pixmap);
    m_pLabelIcon->setScaledContents (true);

    //记住密码，自动登录
    m_pCbxRemember = new QCheckBox(this);
    m_pCbxRemember->setText (QStringLiteral("记住密码"));

    m_pPbnRegister = new QPushButton(this);
    m_pPbnRegister->setText (QStringLiteral("注册"));
    m_pPbnRegister->setFlat (true);

    m_pPbnForgon = new QPushButton(this);
    m_pPbnForgon->setText (QStringLiteral("忘记密码"));
    m_pPbnForgon->setFlat (true);

    m_pCbxAutoLogin = new QCheckBox(this);
    m_pCbxAutoLogin->setText (QStringLiteral("自动登录"));

    m_pPbnLogin = new QPushButton(this);
    m_pPbnLogin->setFixedSize (200,30);
    m_pPbnLogin->setText (QStringLiteral("登录"));

    m_pLetName->setFixedSize (180,30);
    m_pLetPwd->setFixedSize (180,30);

    m_pGMainLayout = new QGridLayout(this);
    //添加头像,0,0,3,1
    m_pGMainLayout->addWidget (m_pLabelIcon,0,0,3,1);
    //用户名输入框
    m_pGMainLayout->addWidget (m_pLetName,0,1,1,2);
    m_pGMainLayout->addWidget (m_pPbnRegister,0,4);
    //密码输入框
    m_pGMainLayout->addWidget (m_pLetPwd,1,1,1,2);
    m_pGMainLayout->addWidget (m_pPbnForgon,1,4);
    //记住密码
    m_pGMainLayout->addWidget (m_pCbxRemember,2,1,1,1,Qt::AlignHCenter | Qt::AlignVCenter);
    //自动登录
    m_pGMainLayout->addWidget (m_pCbxAutoLogin,2,2,1,1,Qt::AlignHCenter | Qt::AlignVCenter);

    //登录
    m_pGMainLayout->addWidget (m_pPbnLogin,3,1,1,2);

    m_pGMainLayout->setHorizontalSpacing (10);
    m_pGMainLayout->setVerticalSpacing (10);
    m_pGMainLayout->setContentsMargins (10,10,10,10);
    setLayout (m_pGMainLayout);
}

void LoginWidget::initBean()
{
    m_pAppBean = new AppBean(this);
}

void LoginWidget::initConnect()
{
    connect (m_pPbnLogin,SIGNAL(clicked(bool)),
             this,SLOT(slotLoginClicked()));

    connect (this,SIGNAL(signalSendLoginInfo(QString)),
             m_pAppBean,SIGNAL(signalSendToServer(QString)));
}

void LoginWidget::slotLoginClicked()
{
    //下面是测试通信数据，具体还需要指定通信协议
    QString testStr;
    testStr = "hello is client!";

    emit signalSendLoginInfo (testStr);
}

