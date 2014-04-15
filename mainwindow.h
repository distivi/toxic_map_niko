#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

#include "src/ToxicCalc.hpp"
#include <src/ExQGraphicsScene.h>
#include "inputparamsdialog.h"
#include "ExportImageDialog.h"
#include "ProgressBarWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void load();

public slots:
    void add_object(QPointF pos, qreal height, qreal width, int wind_direction);
    void moused();
    void draw();
    void zoomIn();
    void zoomOut();
    void exportImage();
    void exportCalled();
    void showProgressBar();

private:
    Ui::MainWindow *ui;
    QGraphicsView* view;
    ExQGraphicsScene* scene;
    InputParamsDialog* inputParams;
    ExportImageDialog* exportImageDialog;
    ProgressBarWidget* progressBar;
    qreal zoomFactor;
};

#endif // MAINWINDOW_H
