#include "login.h"
#include "ui_login.h"
#include <QProcess>
#include <QString>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QStringList arguments;

}
