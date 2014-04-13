#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inputParamsDialog = new InputParamsDialog(this);
    this->mapImg.load("media/map.png");
    scaleFactor=.2;
    scrollH=0;
    scrollV=0;

    this->updateMap(scaleFactor);

    //QObject::connect(this->displayImgLbl,SIGNAL(mousePressEvent(QMouseEvent*) ),this,SLOT(mouseClicked(QMouseEvent*)));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setParamsBtnPressed()));
    QObject::connect(inputParamsDialog,SIGNAL(accepted()),this,SLOT(calculate()));
    QObject::connect(ui->zoomInBtn,SIGNAL(clicked()),this,SLOT(zoomIn()));
    QObject::connect(ui->zoomOutBtn,SIGNAL(clicked()),this,SLOT(zoomOut()));
}

void MainWindow::updateMap(double scaleFactor)
{
    displayImgLbl = new QLabel("");
    displayImgLbl->setPixmap(QPixmap::fromImage(mapImg.scaled(scaleFactor*this->mapImg.width(),scaleFactor*this->mapImg.height())));
    displayImgLbl->resize(displayImgLbl->pixmap()->size());
    displayImgLbl->adjustSize();
    scrollH = ui->scrollArea->horizontalScrollBar()->value();
    scrollV = ui->scrollArea->verticalScrollBar()->value();
    qDebug() << "VSB start value" << ui->scrollArea->horizontalScrollBar()->value();
    this->adjustScrollBar(ui->scrollArea->horizontalScrollBar(),scaleFactor,scrollH);
    this->adjustScrollBar(ui->scrollArea->verticalScrollBar(),scaleFactor,scrollV);
    qDebug() << "VSB updated value" << ui->scrollArea->horizontalScrollBar()->value();
    ui->scrollArea->setWidget(displayImgLbl);

    QCursor cursor;
    qDebug()<<"Cur pos" <<cursor.pos();


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
    std::map<std::string,std::string> data = inputParamsDialog->getCalculationParamsMap();
    calc.define_deep(data["svsp"],data["temp"],data["chemicals"],data["ohv_value"],data["wind"],data["obval"]);

    double width = calc.getWidth();
    qDebug()<< "Calculated width=" << width;

    ui->calculatedWidthEdit->setText(QString::number(width));
}

void MainWindow::zoomIn()
{
    scaleFactor+=.1;
    qDebug()<< displayImgLbl->pixmap()->size();
    this->updateMap(scaleFactor);
    qDebug()<< displayImgLbl->pixmap()->size();

}

void MainWindow::zoomOut()
{
    scaleFactor-=.1;
    qDebug()<< displayImgLbl->pixmap()->size() << displayImgLbl->size();
    this->updateMap(scaleFactor);
    qDebug()<< displayImgLbl->pixmap()->size() << displayImgLbl->size();
    //this->adjustScrollBar(ui->scrollArea->horizontalScrollBar(),scaleFactor);
    //this->adjustScrollBar(ui->scrollArea->verticalScrollBar(),scaleFactor);

}

void MainWindow::adjustScrollBar(QScrollBar* scrollBar,double scaleFactor, int lastValue)
{
    qDebug() << "SB old value" << scrollBar->value();
    qDebug() << "lastValue=" << lastValue;
    scrollBar->setValue(int(10*scaleFactor * lastValue));
    qDebug() << "SB new value" << scrollBar->value();
}
