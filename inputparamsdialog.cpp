#include "inputparamsdialog.h"
#include "ui_inputparamsdialog.h"
#include <QDebug>

InputParamsDialog::InputParamsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputParamsDialog)
{
    dbParamsAdapterMap["Изотермия"] = "izoterm";
    dbParamsAdapterMap["Инверсия"] = "inversion";
    dbParamsAdapterMap["Хлор"] = "chlorine";
    dbParamsAdapterMap["Амиак"] = "ammonia";
    ui->setupUi(this);
    this->setTemperatureValues();

    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setTemperatureValues()));
}

InputParamsDialog::~InputParamsDialog()
{
    delete ui;
}

std::map<std::string,std::string> InputParamsDialog::getCalculationParamsMap()
{
    QString svsp = ui->comboBox->currentText();
    QString temp = ui->comboBox_2->currentText();
    QString chemicals = ui->comboBox_3->currentText();
    QString ohv_value = ui->comboBox_4->currentText();
    int obval = ui->comboBox_5->currentIndex()+1;
    int wind = ui->comboBox_6->currentIndex()+1;

    params["svsp"] = dbParamsAdapterMap[svsp.toStdString()];
    params["temp"] = temp.toStdString();
    params["chemicals"] = dbParamsAdapterMap[chemicals.toStdString()];
    params["ohv_value"] = ohv_value.toStdString();
    params["obval"] = QString::number(obval).toStdString();
    params["wind"] = QString::number(wind).toStdString();

    qDebug()<<svsp << temp << chemicals <<ohv_value<<obval<<wind;

    return this->params;
}

void InputParamsDialog::setTemperatureValues()
{
    /* Defines temperature values according to svsp type */

    ui->comboBox_2->clear();
    if(ui->comboBox->currentText() == "Изотермия")
    {
        ui->comboBox_2->addItem("-20");
        ui->comboBox_2->addItem("0");
        ui->comboBox_2->addItem("+20");
        ui->comboBox_2->addItem("+40");
    }
    else
    {
        ui->comboBox_2->addItem("-20");
        ui->comboBox_2->addItem("0");
        ui->comboBox_2->addItem("+20");
    }

}
