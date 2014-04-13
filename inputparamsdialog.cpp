#include "inputparamsdialog.h"
#include "ui_inputparamsdialog.h"
#include <QDebug>

InputParamsDialog::InputParamsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputParamsDialog)
{
    ui->setupUi(this);
}

InputParamsDialog::~InputParamsDialog()
{
    delete ui;
}

/*void InputParamsDialog::emitCalculateSignal()
{
    qDebug()<<"Acepted";
    emit ready();
    qDebug()<<"ready emited, I hope";
}
*/
std::map<std::string,std::string> InputParamsDialog::getCalculationParamsMap()
{
    return this->params;
}
