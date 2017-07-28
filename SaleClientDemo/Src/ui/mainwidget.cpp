#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    init ();
}

MainWidget::~MainWidget()
{

}

void MainWidget::init()
{
    initForm ();

    initWidget ();

    initConnect ();
}

void MainWidget::initForm()
{
    this->setWindowTitle ("client");
}

void MainWidget::initWidget()
{
    //
}

void MainWidget::initConnect()
{
    //
}
