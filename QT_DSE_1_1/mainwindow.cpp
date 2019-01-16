#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpwithcommand.h"
//#include "login.h"
#include "newfile.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    HelpWithCommand helpwithcommand;
    helpwithcommand.setModal(true);
    helpwithcommand.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    //Login login;
    //login.setModal(true);
    //login.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->customPlot->clearGraphs();

    // create and set the graph:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond,6));
    ui->customPlot->graph(0)->setPen(QPen(Qt::red));
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("Area");
    ui->customPlot->yAxis->setLabel("Latency");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, (x_max+200));
    ui->customPlot->yAxis->setRange(0, (y_max+10));
    // set data and plot
    ui->customPlot->graph(0)->setData(result_base[2], result_base[3]);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->replot();


    if(ui->radioButton->isChecked()){

        for(i = 0; i <= breakpoint_all.size(); i++)
        {
            // create and set the graph:
            ui->customPlot->addGraph();
            ui->customPlot->graph(i+1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,4));
            if(i!=breakpoint_all.size())
            {
                if((method_all[breakpoint_all[i]]=="ES")||(method_all[breakpoint_all[i]]=="GA"))
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::green));
                else if(method_all[breakpoint_all[i]]=="ES_ReSyn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::blue));
                else if(method_all[breakpoint_all[i]]=="DSE")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGreen));
                else if(method_all[breakpoint_all[i]]=="ES_Mrgn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGray));
            }
            else
            {
                if((method_all[breakpoint_all[i-1]+1]=="ES")||(method_all[breakpoint_all[i-1]+1]=="GA"))
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::green));
                else if(method_all[breakpoint_all[i-1]+1]=="ES_ReSyn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::blue));
                else if(method_all[breakpoint_all[i-1]+1]=="DSE")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGreen));
                else if(method_all[breakpoint_all[i-1]+1]=="ES_Mrgn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGray));

            }
            // give the axes some labels:
            ui->customPlot->xAxis->setLabel("Area");
            ui->customPlot->yAxis->setLabel("Latency");
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(0, (x_max+200));
            ui->customPlot->yAxis->setRange(0, (y_max+10));
            // set data and plot
            if(itm_parent.at(i)->checkState(0) == Qt::Checked)
            {
                ui->customPlot->graph(i+1)->setData(x_all[i], y_all[i]);
                ui->customPlot->graph(i+1)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot->replot();
            }
        }
    }

    if(ui->radioButton_2->isChecked()){

        for(i = 0; i <= breakpoint_op.size(); i++)
        {
            // create and set the graph:
            ui->customPlot->addGraph();
            ui->customPlot->graph(i+1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,4));
            if(i!=breakpoint_op.size())
            {
                if((method_op[breakpoint_op[i]]=="ES")||(method_op[breakpoint_op[i]]=="GA"))
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::green));
                else if(method_op[breakpoint_op[i]]=="ES_ReSyn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::blue));
                else if(method_op[breakpoint_op[i]]=="DSE")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGreen));
                else if(method_op[breakpoint_op[i]]=="ES_Mrgn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGray));

            }
            else
            {
                if((method_op[breakpoint_op[i-1]+1]=="ES")||(method_op[breakpoint_op[i-1]+1]=="GA"))
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::green));
                else if(method_op[breakpoint_op[i-1]+1]=="ES_ReSyn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::blue));
                else if(method_op[breakpoint_op[i-1]+1]=="DSE")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGreen));
                else if(method_op[breakpoint_op[i-1]+1]=="ES_Mrgn")
                    ui->customPlot->graph(i+1)->setPen(QPen(Qt::darkGray));

            }
            // give the axes some labels:
            ui->customPlot->xAxis->setLabel("Area");
            ui->customPlot->yAxis->setLabel("Latency");
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(0, (x_max+200));
            ui->customPlot->yAxis->setRange(0, (y_max+10));
            // set data and plot
            if(itm_parent.at(i)->checkState(0) == Qt::Checked)
            {
                ui->customPlot->graph(i+1)->setData(x_op[i], y_op[i]);
                ui->customPlot->graph(i+1)->setLineStyle(QCPGraph::lsLine);
                ui->customPlot->replot();
            }

        }

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString sDominance;
    QString sADRS;
    QString sHypervolume;
    int out_count = 0;
    for(i = 0; i < Dominance.size(); i++)
    {
        if(itm_parent.at(i)->checkState(0) == Qt::Checked)
        {
            sDominance = QString::number(Dominance.at(i)*100.0,10,4) + "%";
            sADRS = QString::number(ADRS.at(i)*100.0,10,4) + "%";
            sHypervolume = QString::number(Hypervolume.at(i)*100,10,4) + "%";
            out_count++;
        }
    }
    if(out_count==1)
    {
        ui->label_6->setText(sDominance);
        ui->label_4->setText(sADRS);
        ui->label_5->setText(sHypervolume);
    }
    else
    {
        ui->label_6->setText("N/A");
        ui->label_4->setText("N/A");
        ui->label_5->setText("N/A");
    }
}

void MainWindow::on_actionnew_triggered()
{
    Newfile newfile;
    newfile.setModal(true);
    newfile.exec();
    if(newfile.read_valid == true)
    {
        QFile file(newfile.filename);
        if (!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this, "title", "file not open");
        }
        else{
            QTextStream in(&file);
            result_all.resize(4);
            result_op.resize(4);
            result_base.resize(4);

            // read title line
            text_line = in.readLine();
            list = text_line.split(",",QString::SkipEmptyParts);
            // set treewidget label
            ui->treeWidget->setColumnCount(list.size());
            ui->treeWidget->setHeaderLabels(list);

            // read the first data line
            text_line = in.readLine();
            while (text_line.length()<=45) {
                text_line = in.readLine();
            }

            // read the first line data
            list = text_line.split(",",QString::SkipEmptyParts);
            //set to data structure
            method_all.append(list.at(0));
            method_history = list.at(0);
            iteration_history = list.at(1).toDouble();
            result_all[0].append(list.at(1).toDouble());
            result_all[1].append(list.at(2).toDouble());
            result_all[2].append(list.at(3).toDouble());
            result_all[3].append(list.at(21).toDouble());

            method_op.append(list.at(0));
            result_op[0].append(list.at(1).toDouble());
            result_op[1].append(list.at(2).toDouble());
            result_op[2].append(list.at(3).toDouble());
            result_op[3].append(list.at(21).toDouble());

            result_base[0].append(list.at(1).toDouble());
            result_base[1].append(list.at(2).toDouble());
            result_base[2].append(list.at(3).toDouble());
            result_base[3].append(list.at(21).toDouble());


            // set to tree widget
            itm_parent.append(new QTreeWidgetItem(ui->treeWidget));
            itm_parent.last()->setCheckState(0,Qt::Unchecked);
            itm_parent.last()->setText(0,list.at(0));
            itm_parent.last()->setText(1,list.at(1));
            ui->treeWidget->addTopLevelItem(itm_parent.last());

            itm_child.append(new QTreeWidgetItem());
            for(i = 0; i < list.size(); i++)
            {
                itm_child.last()->setText(i,list.at(i));
            }
            itm_parent.last()->addChild(itm_child.last());


            // count the scale of the data
            x_max = result_all[2].last();
            y_max = result_all[3].last();

            while (!in.atEnd()){
                // read one line
                text_line = in.readLine();
                while (text_line.length()<=45) {
                    //QMessageBox::information(this,tr("the title"),tr("invalid line found"));
                    text_line = in.readLine();
                }
                list = text_line.split(",",QString::SkipEmptyParts);

                // set to data structure
                method_all.append(list.at(0));
                result_all[0].append(list.at(1).toDouble());
                result_all[1].append(list.at(2).toDouble());
                result_all[2].append(list.at(3).toDouble());
                result_all[3].append(list.at(21).toDouble());

                // count the data scale
                if(result_all[2].last() > x_max)
                    x_max = result_all[2].last();
                if(result_all[3].last() > y_max)
                    y_max = result_all[3].last();

                // meet a new iteration's data
                if((method_all.last()!=method_history)||(result_all[0].last()!=iteration_history))
                {
                    method_history = method_all.last();
                    iteration_history = result_all[0].last();

                    breakpoint_all.append(counter_all);
                    breakpoint_op.append(counter_op);

                    method_op.append(list.at(0));
                    result_op[0].append(result_all[0].last());
                    result_op[1].append(result_all[1].last());
                    result_op[2].append(result_all[2].last());
                    result_op[3].append(result_all[3].last());
                    counter_op++;
                    op_begin = counter_op;

                    // set to tree widget
                    itm_parent.append(new QTreeWidgetItem(ui->treeWidget));
                    itm_parent.last()->setCheckState(0,Qt::Unchecked);
                    itm_parent.last()->setText(0,list.at(0));
                    itm_parent.last()->setText(1,list.at(1));
                    ui->treeWidget->addTopLevelItem(itm_parent.last());

                }

                // set to tree widget
                itm_child.append(new QTreeWidgetItem());
                for(i = 0; i < list.size(); i++)
                {
                    itm_child.last()->setText(i,list.at(i));
                }
                itm_parent.last()->addChild(itm_child.last());



                counter_all++;

                decision_op = 1;  // "1" means keep, "0" means discard
                for(i = op_begin; i < result_op[2].size(); i++)
                {
                    if((result_all[2].last() >= result_op[2].at(i))&&(result_all[3].last() >= result_op[3].at(i)))
                    {
                        decision_op = 0;   // someone in the optimum array is better than the current one, drop it.
                    }
                    else if((result_all[2].last() <= result_op[2].at(i))&&(result_all[3].last() <= result_op[3].at(i)))
                    {
                        method_op.remove(i);
                        result_op[0].remove(i);
                        result_op[1].remove(i);
                        result_op[2].remove(i);
                        result_op[3].remove(i);
                        i--;
                        counter_op--;
                    }
                }
                if(decision_op == 1)
                {
                    method_op.append(list.at(0));
                    result_op[0].append(result_all[0].last());
                    result_op[1].append(result_all[1].last());
                    result_op[2].append(result_all[2].last());
                    result_op[3].append(result_all[3].last());
                    counter_op++;
                }

                decision_base = 1;  // "1" means keep, "0" means discard
                for(i = 0; i < result_base[2].size(); i++)
                {
                    if((result_all[2].last() >= result_base[2].at(i))&&(result_all[3].last() >= result_base[3].at(i)))
                    {
                        decision_base = 0;   // someone in the optimum array is better than the current one, drop it.
                    }
                    else if((result_all[2].last() <= result_base[2].at(i))&&(result_all[3].last() <= result_base[3].at(i)))
                    {
                        result_base[0].remove(i);
                        result_base[1].remove(i);
                        result_base[2].remove(i);
                        result_base[3].remove(i);
                        i--;
                    }
                }
                if(decision_base == 1)
                {
                    result_base[0].append(result_all[0].last());
                    result_base[1].append(result_all[1].last());
                    result_base[2].append(result_all[2].last());
                    result_base[3].append(result_all[3].last());
                }

            }


            // rearrange data for all
            x_all.resize(breakpoint_all.size()+1);
            y_all.resize(breakpoint_all.size()+1);
            begin_point = 0;
            end_point = breakpoint_all.at(0);
            for(i = 0; i <= breakpoint_all.size(); i++)
            {
                for(j = begin_point; j <= end_point; j++)
                {
                    x_all[i].append(result_all[2][j]);
                    y_all[i].append(result_all[3][j]);
                }
                begin_point = end_point+1;
                if(i == (breakpoint_all.size()-1))
                    end_point = result_all[0].size()-1;
                else if(i != breakpoint_all.size())
                    end_point = breakpoint_all.at(i+1);
            }

            // resrrange data for optimum trade-off
            x_op.resize(breakpoint_op.size()+1);
            y_op.resize(breakpoint_op.size()+1);
            begin_point = 0;
            end_point = breakpoint_op.at(0);
            for(i = 0; i <= breakpoint_op.size(); i++)
            {
                for(j = begin_point; j <= end_point; j++)
                {
                    x_op[i].append(result_op[2][j]);
                    y_op[i].append(result_op[3][j]);
                }
                begin_point = end_point+1;
                if(i == (breakpoint_op.size()-1))
                    end_point = result_op[0].size()-1;
                else if(i != breakpoint_op.size())
                    end_point = breakpoint_op.at(i+1);
            }

            // Calculate dominance
            for(i = 0; i < x_op.size(); i++)
            {
                dominance_counter = 0.0;
                for(j = 0; j < x_op[i].size(); j++)
                {
                    for(k = 0; k < result_base[0].size(); k++)
                    {
                        if((x_op[i][j]==result_base[2][k])&&(y_op[i][j]==result_base[3][k]))
                        {
                            dominance_counter++;
                        }
                    }
                }
                Dominance.append(dominance_counter/result_base[0].size());
            }

            // Calculate ADRS
            double distance;
            double buffer;
            double adrs;
            double adrs0;
            double adrs1;
            int mark;
            for(i = 0; i < x_op.size(); i++)        // each trade-off line
            {
                adrs0 = 0.0;
                for(j = 0; j < result_base[0].size(); j++)      // each base line point
                {
                    for(k = 0; k < x_op[i].size(); k++)     // each trade-off point
                    {
                        if(k == 0)
                        {
                            distance = sqrt(pow((result_base[2][j]-x_op[i][k]),2)+pow((result_base[3][j]-y_op[i][k]),2));
                        }
                        else
                        {
                            buffer = sqrt(pow((result_base[2][j]-x_op[i][k]),2)+pow((result_base[3][j]-y_op[i][k]),2));
                            distance = (buffer<distance)?buffer:distance;
                        }
                    }
                    distance = distance / sqrt(pow(result_base[2][j],2)+pow(result_base[3][j],2));
                    adrs0 += distance;
                }
                adrs0 /= result_base[0].size();

                adrs1 = 0.0;
                for(j = 0; j < x_op[i].size(); j++)      // each trade-off point
                {
                    for(k = 0; k < result_base[0].size(); k++)     // each base line point
                    {
                        if(k == 0)
                        {
                            distance = sqrt(pow((result_base[2][k]-x_op[i][j]),2)+pow((result_base[3][k]-y_op[i][j]),2));
                            mark = k;
                        }
                        else
                        {
                            buffer = sqrt(pow((result_base[2][k]-x_op[i][j]),2)+pow((result_base[3][k]-y_op[i][j]),2));
                            if(buffer < distance)
                                mark = k;
                            distance = (buffer<distance)?buffer:distance;
                        }
                    }
                    distance = distance / sqrt(pow(result_base[2][mark],2)+pow(result_base[3][mark],2));
                    adrs1 += distance;
                }
                adrs1 /= x_op[i].size();

                adrs = (adrs0 + adrs1) / 2;
                ADRS.append(adrs);
            }

            // Calculate Hypervolume
            QVector< double > xcal_baseline;
            QVector< double > ycal_baseline;
            QVector< QVector<double> > xcal_tradeoff;
            QVector< QVector<double> > ycal_tradeoff;
            double buf_switch;
            for(i = 0; i < result_base[0].size(); i++)      // copy data into *cal_baseline
            {
                xcal_baseline.append(result_base[2][i]);
                ycal_baseline.append(result_base[3][i]);
            }
            for(i = 0; i < xcal_baseline.size(); i++)       // bubble sort *cal_baseline
            {
                for(j = i; j < xcal_baseline.size(); j++)
                {
                    if(xcal_baseline[j] < xcal_baseline[i])
                    {
                        buf_switch = xcal_baseline[i];
                        xcal_baseline.replace(i, xcal_baseline[j]);
                        xcal_baseline.replace(j, buf_switch);

                        buf_switch = ycal_baseline[i];
                        ycal_baseline.replace(i, ycal_baseline[j]);
                        ycal_baseline.replace(j, buf_switch);
                    }
                }
            }

            xcal_tradeoff.resize(x_op.size());
            ycal_tradeoff.resize(y_op.size());
            for(i = 0; i < x_op.size(); i++)        // copy data into *cal_tradeoff
            {
                for(j = 0; j < x_op[i].size(); j++)
                {
                    xcal_tradeoff[i].append(x_op[i][j]);
                    ycal_tradeoff[i].append(y_op[i][j]);
                }
            }
            for(i = 0; i < xcal_tradeoff.size(); i++)       // bubble sort *cal_tradeoff
            {
                for(j = 0; j < xcal_tradeoff[i].size(); j++)
                {
                    for(k = j; k < xcal_tradeoff[i].size(); k++)
                    {
                        if(xcal_tradeoff[i][k] < xcal_tradeoff[i][j])
                        {
                            buf_switch = xcal_tradeoff[i][j];
                            xcal_tradeoff[i].replace(j, xcal_tradeoff[i][k]);
                            xcal_tradeoff[i].replace(k, buf_switch);

                            buf_switch = ycal_tradeoff[i][j];
                            ycal_tradeoff[i].replace(j, ycal_tradeoff[i][k]);
                            ycal_tradeoff[i].replace(k, buf_switch);
                        }
                    }
                }
            }

            // calaulate hypervolume
            double xb_start, yb_start, xb_end, yb_end;
            double xt_start, yt_start, xt_end, yt_end;
            double area0, area1, area2;
            for(i = 0; i < xcal_tradeoff.size(); i++)
            {
                if(xcal_baseline[0] <= xcal_tradeoff[i][0])      // set start point
                {
                    xb_start = xcal_baseline[0];
                    xt_start = xcal_baseline[0];
                    yb_start = ycal_baseline[0];
                    yt_start = ycal_baseline[0];
                }
                else
                {
                    xb_start = xcal_tradeoff[i][0];
                    xt_start = xcal_tradeoff[i][0];
                    yb_start = ycal_tradeoff[i][0];
                    yt_start = ycal_tradeoff[i][0];
                }

                if(xcal_baseline.last() < xcal_tradeoff[i].last())      // set end point
                {
                    xb_end = xcal_tradeoff[i].last();
                    xt_end = xcal_tradeoff[i].last();
                    yb_end = ycal_tradeoff[i].last();
                    yt_end = ycal_tradeoff[i].last();
                }
                else
                {
                    xb_end = xcal_baseline.last();
                    xt_end = xcal_baseline.last();
                    yb_end = ycal_baseline.last();
                    yt_end = ycal_baseline.last();
                }

                // calculate two area
                area0 = 0.0;
                area1 = 0.0;
                area2 = 0.0;
                for(j = 0; j <= xcal_baseline.size(); j++)
                {
                    if(j == 0)
                        area0 += (yb_start + ycal_baseline[0])*(xcal_baseline[0]-xb_start)/2.0;
                    else if(j != xcal_baseline.size())
                        area0 += (ycal_baseline[j]+ycal_baseline[j-1])*(xcal_baseline[j]-xcal_baseline[j-1])/2.0;
                    else
                        area0 += (yb_end + ycal_baseline.last())*(xb_end - xcal_baseline.last())/2.0;
                }
                area2 = area0 + (yb_start * xb_start)/2.0 - (yb_end * xb_end)/2.0;

                for(j = 0; j <= xcal_tradeoff[i].size(); j++)
                {
                    if(j == 0)
                        area1 += (yt_start + ycal_tradeoff[i][0])*(xcal_tradeoff[i][0]-xt_start)/2.0;
                    else if(j != xcal_tradeoff[i].size())
                        area1 += (ycal_tradeoff[i][j]+ycal_tradeoff[i][j-1])*(xcal_tradeoff[i][j]-xcal_tradeoff[i][j-1])/2.0;
                    else
                        area1 += (yt_end + ycal_tradeoff[i].last())*(xt_end - xcal_tradeoff[i].last())/2.0;
                }

                Hypervolume.append((area1-area0)/area2);
            }
            file.close();
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionHelp_triggered()
{
    HelpWithCommand help_page;
    help_page.setModal(true);
    help_page.exec();
}

void MainWindow::on_pushButton_clicked()
{
    QString cmd_input_qs = ui->textEdit->toPlainText();
    const char* cmd_input_ch = cmd_input_qs.toLatin1();
    const char* cmd = cmd_input_ch;
    system(cmd);
}
