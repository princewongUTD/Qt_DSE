#include "helpwithcommand.h"
#include "ui_helpwithcommand.h"

HelpWithCommand::HelpWithCommand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWithCommand)
{
    ui->setupUi(this);
}

HelpWithCommand::~HelpWithCommand()
{
    delete ui;
}
