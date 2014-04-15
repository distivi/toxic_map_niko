#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new QGraphicsView;
    scene = new ExQGraphicsScene;
    inputParams = new InputParamsDialog;
    exportImageDialog = new ExportImageDialog;
    progressBar = new ProgressBarWidget;
    this->zoomFactor=1.2;
    this->load();

    QObject::connect(this->scene,SIGNAL(mouse_pressed()),this,SLOT(moused()));
    QObject::connect(inputParams,SIGNAL(accepted()),this,SLOT(draw()));
    QObject::connect(ui->closeBtn,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->closeBtn,SIGNAL(clicked()),this->view,SLOT(close()));
    QObject::connect(ui->zoomInBtn,SIGNAL(clicked()),this,SLOT(zoomIn()));
    QObject::connect(ui->zoomOutBtn,SIGNAL(clicked()),this,SLOT(zoomOut()));
    QObject::connect(ui->exportBtn,SIGNAL(clicked()),this,SLOT(exportCalled()));
    QObject::connect(exportImageDialog,SIGNAL(accepted()),this,SLOT(exportImage()));
    QObject::connect(exportImageDialog,SIGNAL(accepted()),this,SLOT(showProgressBar()));
    QObject::connect(exportImageDialog,SIGNAL(accepted()),this->progressBar,SLOT(start()));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load()
{
    QPixmap map("media/map.png");

    //QGraphicsEllipseItem *item = new QGraphicsEllipseItem( 0 );
    //item->setRect( 0.0, 0.0, 100.0, 100.0 );
    //item->setFlag(QGraphicsItem::ItemIsMovable);

    scene->addPixmap(map);
    //scene->addItem(item);

    //item->setPos(1000,1000);
    //item->setScale(qreal(2));

    view->setScene(scene);
    view->show();
}

void MainWindow::add_object(QPointF pos,qreal height, qreal width, int wind_direction)
{
    //QGraphicsEllipseItem *item = new QGraphicsEllipseItem( 0 );
    //item->setRect( 0, 0, height, width );

    scene->addEllipse(pos.x()-width,pos.y()-width,width*2,height*2);
    scene->addEllipse(pos.x(),pos.y(),1,1);
    qDebug() << width << height;

    //item->setFlag(QGraphicsItem::ItemIsMovable);
    //item->setPos(pos);
    //qDebug()<< "POS:" <<pos;
    //item->setScale(qreal(1));
    //item->setRotation(0+90*wind_direction);
    //scene->addItem(item);

    //QGraphicsEllipseItem *center_dot = new QGraphicsEllipseItem( 0 );
    //center_dot->setRect( 0.0, 0.0, 1, 1 );
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    //center_dot->setPos(pos.x(),pos.y());
    //qDebug()<< "DotPosPOS:" <<pos;
    //center_dot->setScale(qreal(1));
    //center_dot->setRotation(0+90*wind_direction);
    //scene->addItem(center_dot);
}

void MainWindow::moused()
{
    inputParams->show();
}

void MainWindow::draw()
{
    ToxicCalc calc;
    std::map<std::string,std::string> data = this->inputParams->getCalculationParamsMap();
    calc.define_deep(data["svsp"],data["temp"],data["chemicals"],data["ohv_value"],data["wind"],data["obval"]);
    float wind_dx = atoi(data["wind"].c_str());
    this->add_object(QPointF(scene->getPos().x(),scene->getPos().y()), calc.getWidth()*1000*0.3/2+5*wind_dx, calc.getWidth()*1000*0.3/2+5*wind_dx, atoi(data["wind_direction"].c_str()));
    ui->lineEdit->setText(QString::number(calc.getWidth()));
    ui->lineEdit_2->setText(QString::number(calc.getWidth()));
    ui->lineEdit_3->setText(QString(data["object"].c_str()));

}

void MainWindow::zoomIn()
{
    this->view->scale(zoomFactor,zoomFactor);
        qDebug()<<"+Zoom factor"<< zoomFactor;
}

void MainWindow::zoomOut()
{
    this->view->scale(1/zoomFactor, 1/zoomFactor);
    qDebug()<<"-Zoom factor" << zoomFactor;
}

void MainWindow::exportImage()
{

    QString name = QString("exported/")+this->exportImageDialog->getFileName();
    qDebug() << name;
    QPixmap* toSave = new QPixmap(6000,8000);
    QPainter painter(toSave);
    this->scene->render(&painter);
    painter.end();

    toSave->save(name.toStdString().c_str());
}

void MainWindow::exportCalled()
{
    this->exportImageDialog->show();

}

void MainWindow::showProgressBar()
{
     progressBar->show();
}
