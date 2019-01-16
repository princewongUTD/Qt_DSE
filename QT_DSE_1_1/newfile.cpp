#include "newfile.h"
#include "ui_newfile.h"

#include <QFileDialog>

Newfile::Newfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newfile)
{
    ui->setupUi(this);
}

Newfile::~Newfile()
{
    delete ui;
}


void Newfile::on_pushButton_clicked()
{
    filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "CSV File(*.CSV);;All files (*.*);;Text File (*.txt)"
                );
    ui->lineEdit->setText(filename);

}

void Newfile::on_buttonBox_accepted()
{
    read_valid = true;
}

void Newfile::on_buttonBox_rejected()
{
    read_valid = false;
}
