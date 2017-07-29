#include "mainwidget.h"

#include "bean/appbean.h"

#include <QDateTime>
#include <QTextEdit>
#include <QVBoxLayout>

#define DATETIME qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    init ();
}

MainWidget::~MainWidget()
{

}

void MainWidget::init ()
{
    initForm ();

    initWidget ();

    initBean ();

    initConnect ();
}

void MainWidget::initForm ()
{
    this->setWindowTitle (QStringLiteral("saleServer"));

    this->setMinimumSize (640,480);
}

void MainWidget::initWidget()
{
    m_pTextEdit = new QTextEdit(this);

    m_pVMainLayout = new QVBoxLayout(this);
    m_pVMainLayout->addWidget (m_pTextEdit);

    m_pVMainLayout->setContentsMargins (0,0,0,0);

    setLayout (m_pVMainLayout);
}

void MainWidget::initBean()
{
    m_pAppbean = new AppBean(this);
}

void MainWidget::initConnect()
{
    connect (m_pAppbean,SIGNAL(signalSendStr(QString)),
             this,SLOT(slotShowText(QString)));
}

void MainWidget::slotShowText(const QString &str)
{
    if(!str.isEmpty ())
        m_pTextEdit->append (DATETIME + str);
}
