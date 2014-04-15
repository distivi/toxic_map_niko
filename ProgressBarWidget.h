#ifndef PROGRESSBARWIDGET_H
#define PROGRESSBARWIDGET_H

#include <QWidget>

namespace Ui {
class ProgressBarWidget;
}

class ProgressBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBarWidget(QWidget *parent = 0);
    ~ProgressBarWidget();

public slots:
    void start();

private:
    Ui::ProgressBarWidget *ui;
};

#endif // PROGRESSBARWIDGET_H
