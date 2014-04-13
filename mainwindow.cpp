#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputParamsDialog = new InputParamsDialog(this);
    QImage mapImg;
    mapImg.load("media/dawn_of_ubuntu.png");

    displayImgLbl = new QLabel("");
    displayImgLbl->setPixmap(QPixmap::fromImage(mapImg));
    displayImgLbl->adjustSize();

    ui->scrollArea->setWidget(displayImgLbl);

    //QObject::connect(this->displayImgLbl,SIGNAL(mousePressEvent(QMouseEvent*) ),this,SLOT(mouseClicked(QMouseEvent*)));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setParamsBtnPressed()));
    QObject::connect(inputParamsDialog,SIGNAL(accepted()),this,SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseClicked(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) qDebug()<<"Mouse clicked";
    inputParamsDialog->show();
}

void MainWindow::setParamsBtnPressed()
{
    inputParamsDialog->show();
}

void MainWindow::calculate()
{
    qDebug() << "Calсulation started";
}
