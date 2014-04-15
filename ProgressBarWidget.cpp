#include "ProgressBarWidget.h"
#include "ui_progressbarwidget.h"

ProgressBarWidget::ProgressBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBarWidget)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,100);
}

ProgressBarWidget::~ProgressBarWidget()
{
    delete ui;
}

void ProgressBarWidget::start()
{
    for (int i=0; i <=100; i+=10)    ui->progressBar->setValue(i);
    //this->close();
}
