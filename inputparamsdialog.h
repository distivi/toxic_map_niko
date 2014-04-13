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

public slots:
    void setTemperatureValues();

private:
    Ui::InputParamsDialog *ui;
    std::map<std::string,std::string> params;
    std::map<std::string,std::string> dbParamsAdapterMap;
};

#endif // INPUTPARAMSDIALOG_H
