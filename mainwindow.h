#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include "inputparamsdialog.h"
#include <QScrollBar>

#include <src/ToxicCalc.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void mouseClicked(QMouseEvent * e);
    void setParamsBtnPressed();
    void calculate();
    void zoomIn();
    void zoomOut();
    void adjustScrollBar(QScrollBar* scrollBar, double scaleFactor, int lastValue);
    void updateMap(double scaleFactor);

private:
    Ui::MainWindow *ui;
    QLabel* displayImgLbl;
    InputParamsDialog* inputParamsDialog;
    QImage mapImg;
    double scaleFactor;
    int scrollH;
    int scrollV;
    ToxicCalc calc;
};

#endif // MAINWINDOW_H
