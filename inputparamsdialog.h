#ifndef INPUTPARAMSDIALOG_H
#define INPUTPARAMSDIALOG_H

#include <QDialog>
#include <map>

namespace Ui {
class InputParamsDialog;
}

class InputParamsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputParamsDialog(QWidget *parent = 0);
    ~InputParamsDialog();
    std::map<std::string,std::string> getCalculationParamsMap();

private:
    Ui::InputParamsDialog *ui;
    std::map<std::string,std::string> params;
};

#endif // INPUTPARAMSDIALOG_H
