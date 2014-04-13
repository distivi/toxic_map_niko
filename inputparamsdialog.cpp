#include "inputparamsdialog.h"
#include "ui_inputparamsdialog.h"
#include <QDebug>

InputParamsDialog::InputParamsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputParamsDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(emitCalculateSignal()));
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
