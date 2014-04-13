#ifndef INPUTPARAMSDIALOG_H
#define INPUTPARAMSDIALOG_H

#include <QDialog>

namespace Ui {
class InputParamsDialog;
}

class InputParamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputParamsDialog(QWidget *parent = 0);
    ~InputParamsDialog();

private:
    Ui::InputParamsDialog *ui;
};

#endif // INPUTPARAMSDIALOG_H
