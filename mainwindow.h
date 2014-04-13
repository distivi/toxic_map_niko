#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include "inputparamsdialog.h"

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

private:
    Ui::MainWindow *ui;
    QLabel* displayImgLbl;
    InputParamsDialog* inputParamsDialog;
};

#endif // MAINWINDOW_H
