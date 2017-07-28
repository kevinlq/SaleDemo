#include "mainwidget.h"

#include "bean/appbean.h"

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
}

void MainWidget::initWidget()
{
    //
}

void MainWidget::initBean()
{
    m_pAppbean = new AppBean(this);
}

void MainWidget::initConnect()
{
    //
}
