#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionnew_triggered();

    void on_actionExit_triggered();

    void on_actionHelp_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QString filename;

    QString text_line;
    QStringList list;

    QVector< QVector<double> > result_all;
    QVector< QVector<double> > result_op;
    QVector< QVector<double> > result_base;
    QVector< double > ADRS;
    QVector< double > Hypervolume;
    QVector< double > Dominance;
    QVector< QString > method_op;
    QVector< QString > method_all;

    QString method_history;
    double iteration_history;
    int counter_all = 0;
    int counter_op = 0;
    int op_begin = 0;
    QVector< int > breakpoint_all;
    QVector< int > breakpoint_op;

    QVector< QTreeWidgetItem *> itm_parent;
    QVector< QTreeWidgetItem *> itm_child;

    int i,j,k,decision_op,decision_base;
    double x_max, y_max;

    QVector< QVector<double> > x_all;
    QVector< QVector<double> > y_all;
    QVector< QVector<double> > x_op;
    QVector< QVector<double> > y_op;
    int begin_point;
    int end_point;

    double dominance_counter;




};

#endif // MAINWINDOW_H
