#ifndef EXPORTIMAGEDIALOG_H
#define EXPORTIMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class ExportImageDialog;
}

class ExportImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportImageDialog(QWidget *parent = 0);
    ~ExportImageDialog();
    QString getFileName();

public slots:
    void saveFileName();

private:
    Ui::ExportImageDialog *ui;
    QString fileName;
};

#endif // EXPORTIMAGEDIALOG_H
