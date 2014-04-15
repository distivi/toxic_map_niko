#include "ExportImageDialog.h"
#include "ui_exportimagedialog.h"

ExportImageDialog::ExportImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportImageDialog)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(accepted()),this,SLOT(saveFileName()));
}

ExportImageDialog::~ExportImageDialog()
{
    delete ui;
}

QString ExportImageDialog::getFileName()
{
    return this->fileName;
}

void ExportImageDialog::saveFileName()
{
    this->fileName = ui->exportFileNameEdit->text();
}
