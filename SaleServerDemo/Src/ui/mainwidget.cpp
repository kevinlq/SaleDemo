#include "mainwidget.h"

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
}

void MainWidget::initForm ()
{
    this->setWindowTitle (QStringLiteral("saleServer"));
}
