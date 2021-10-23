#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <bits/stdc++.h>
#include <QtCharts>
using namespace std;

void recalculate(QLineSeries *graph, NumericMethod *method){

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chartView = new QChartView(chart);
    chartView->resize(900, 550);
    layout()->addWidget(this->chartView);

//    EulerGraph = new QLineSeries();
//    ExactGraph = new QLineSeries();
//    ImprovedEulerGraph = new QLineSeries();
//    RungeKuttaGraph = new QLineSeries();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::stateCheck(){
    if(!ui->ExactShow->isChecked()){
        ExactGraph->hide();
    }
    else if(ui->ExactShow->isChecked()){
        ExactGraph->show();
    }
    if(!ui->EulerShow->isChecked()){
        EulerGraph->hide();
    }
    else if(ui->EulerShow->isChecked()){
        EulerGraph->show();
    }
    if(!ui->ImprovedEulerShow->isChecked()){
        ImprovedEulerGraph->hide();
    }
    else if(ui->ImprovedEulerShow->isChecked()){
        ImprovedEulerGraph->show();
    }
    if(!ui->RungeKuttaShow->isChecked()){
        RungeKuttaGraph->hide();
    }
    else if(ui->RungeKuttaShow->isChecked()){
        RungeKuttaGraph->show();
    }
}

void MainWindow::on_Sulution_creator_clicked()
{
    chart->removeAllSeries();
    stateCheck();
    double x0, y0, X, h;
    x0 = ui->x0Data->text().toDouble();
    y0 = ui->y0Data->text().toDouble();
    X = ui->XData->text().toDouble();
    h = (X - x0)/(ui->NData->text().toDouble());

    exact = new ExactSolution(x0, y0, X, h);
    euler = new Euler(x0, y0, X, h);
    improvedEuler = new ImprovedEuler(x0, y0, X, h);
    rungeKutta = new RungeKutta(x0, y0, X, h);

    exact->GetSolutions();
    euler->GetSolutions();
    improvedEuler->GetSolutions();
    rungeKutta->GetSolutions();

    for (int i = 0; i < exact->ys.size(); i++) {
        ExactGraph->append(exact->xs[i], exact->ys[i]);
        EulerGraph->append(euler->xs[i], euler->ys[i]);
        ImprovedEulerGraph->append(improvedEuler->xs[i], improvedEuler->ys[i]);
        RungeKuttaGraph->append(rungeKutta->xs[i], rungeKutta->ys[i]);
    }

    if(ExactGraph->chart() != chart) chart->addSeries(ExactGraph);
    if(EulerGraph->chart() != chart) chart->addSeries(EulerGraph);
    if(ImprovedEulerGraph->chart() != chart) chart->addSeries(ImprovedEulerGraph);
    if(RungeKuttaGraph->chart() != chart) chart->addSeries(RungeKuttaGraph);

    chart->createDefaultAxes();
    ExactGraph->setName("Exact Solution");
    EulerGraph->setName("Euler method Solution");
    ImprovedEulerGraph->setName("Improved Euler method solution");
    RungeKuttaGraph->setName("Runge Kutta solution");

    ExactGraph = new QLineSeries();
    EulerGraph = new QLineSeries();
    ImprovedEulerGraph = new QLineSeries();
    RungeKuttaGraph = new QLineSeries();
}


