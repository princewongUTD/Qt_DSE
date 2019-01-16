#ifndef NEWFILE_H
#define NEWFILE_H

#include <QDialog>

namespace Ui {
class Newfile;
}

class Newfile : public QDialog
{
    Q_OBJECT

public:
    explicit Newfile(QWidget *parent = 0);
    ~Newfile();
    QString filename;
    bool read_valid;

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Newfile *ui;
};

#endif // NEWFILE_H
