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
    chartView->resize(900, 700);
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

void MainWindow::getLineData(){
    x0 = ui->x0Data->text().toDouble();
    y0 = ui->y0Data->text().toDouble();
    X = ui->XData->text().toDouble();
    h = (X - x0)/(ui->NData->text().toDouble());
}

void MainWindow::initializeMethod(){
    exact = new ExactSolution(x0, y0, X, h);
    euler = new Euler(x0, y0, X, h);
    improvedEuler = new ImprovedEuler(x0, y0, X, h);
    rungeKutta = new RungeKutta(x0, y0, X, h);
}

void MainWindow::numericSolutions(){
    exact->GetSolutions();
    euler->GetSolutions();
    improvedEuler->GetSolutions();
    rungeKutta->GetSolutions();
}

void MainWindow::addSeriesToChart(){
    chart->addSeries(ExactGraph);
    chart->addSeries(EulerGraph);
    chart->addSeries(ImprovedEulerGraph);
    chart->addSeries(RungeKuttaGraph);
}

void MainWindow::addSeriesToChartLTE(){
    chart->addSeries(EulerGraph);
    chart->addSeries(ImprovedEulerGraph);
    chart->addSeries(RungeKuttaGraph);
}



void MainWindow::on_Solution_creator_clicked()
{
    chart->removeAllSeries();
    stateCheck();
    getLineData();
    initializeMethod();
    numericSolutions();

    for (int i = 0; i < exact->ys.size(); i++) {
        ExactGraph->append(exact->xs[i], exact->ys[i]);
        EulerGraph->append(euler->xs[i], euler->ys[i]);
        ImprovedEulerGraph->append(improvedEuler->xs[i], improvedEuler->ys[i]);
        RungeKuttaGraph->append(rungeKutta->xs[i], rungeKutta->ys[i]);
    }
    addSeriesToChart();
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



void MainWindow::on_LTE_graph_clicked()
{
    chart->removeAllSeries();
    stateCheck();
    getLineData();
    initializeMethod();
    numericSolutions();

    for (int i = 0; i < exact->ys.size(); i++) {
        EulerGraph->append(euler->xs[i], abs(exact->ys[i] - euler->ys[i]));
        ImprovedEulerGraph->append(improvedEuler->xs[i], abs(exact->ys[i] - improvedEuler->ys[i]));
        RungeKuttaGraph->append(rungeKutta->xs[i], abs(exact->ys[i] - rungeKutta->ys[i]));
    }

    addSeriesToChartLTE();

    chart->createDefaultAxes();

    EulerGraph->setName("Euler method LTE");
    ImprovedEulerGraph->setName("Improved Euler method LTE");
    RungeKuttaGraph->setName("Runge Kutta LTE");

    EulerGraph = new QLineSeries();
    ImprovedEulerGraph = new QLineSeries();
    RungeKuttaGraph = new QLineSeries();

}


void MainWindow::on_GTE_graph_clicked()
{
    chart->removeAllSeries();
    stateCheck();
    getLineData();

    int maxSteps = ui->NData->text().toInt();
    int nStart = ui->n0Data->text().toInt();

    for(int n = nStart; n <= maxSteps; n++){

        h = (X - x0)/n;
        initializeMethod();
        numericSolutions();
        double eulerMax = 0, improvedEulerMax = 0, rungeKuttaMax = 0;

        for(int i = 0; i < exact->ys.size(); i++){
            eulerMax = max(eulerMax, abs(exact->ys[i] - euler->ys[i]));
            improvedEulerMax = max(improvedEulerMax, abs(exact->ys[i] - improvedEuler->ys[i]));
            rungeKuttaMax = max(rungeKuttaMax, abs(exact->ys[i] - rungeKutta->ys[i]));
        }

        EulerGraph->append(n, eulerMax);
        ImprovedEulerGraph->append(n, improvedEulerMax);
        RungeKuttaGraph->append(n, rungeKuttaMax);
    }

    addSeriesToChartLTE();

    chart->createDefaultAxes();
    EulerGraph->setName("Euler method GTE");
    ImprovedEulerGraph->setName("Improved Euler method GTE");
    RungeKuttaGraph->setName("Runge Kutta GTE");

    EulerGraph = new QLineSeries();
    ImprovedEulerGraph = new QLineSeries();
    RungeKuttaGraph = new QLineSeries();
}





