#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <bits/stdc++.h>
#include <QtCharts>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chartView = new QChartView(chart);
    chartView->resize(900, 600);
    layout()->addWidget(this->chartView);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString str = ui->lineEdit->text();
    int num = str.toInt(&ok, 10);
    num++;
    cout<<num<<endl;
    ui->lineEdit->setText(QString::number(num));
}

