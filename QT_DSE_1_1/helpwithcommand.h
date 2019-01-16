#ifndef HELPWITHCOMMAND_H
#define HELPWITHCOMMAND_H

#include <QDialog>

namespace Ui {
class HelpWithCommand;
}

class HelpWithCommand : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWithCommand(QWidget *parent = 0);
    ~HelpWithCommand();

private:
    Ui::HelpWithCommand *ui;
};

#endif // HELPWITHCOMMAND_H
