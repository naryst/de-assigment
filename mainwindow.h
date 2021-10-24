#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "Euler.h"
#include "ExactSolution.h"
#include "ImprovedEuler.h"
#include "RungeKutta.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stateCheck();
    void getLineData();
    void initializeMethod();
    void numericSolutions();
    void addSeriesToChart();
    void addSeriesToChartLTE();
    double x0, y0, X, h;
    QLineSeries *ExactGraph = new QLineSeries();
    QLineSeries *EulerGraph = new QLineSeries();
    QLineSeries *ImprovedEulerGraph = new QLineSeries();
    QLineSeries *RungeKuttaGraph = new QLineSeries();
    QChart *chart = new QChart();
    QChartView *chartView;
    Euler *euler;
    ExactSolution *exact;
    ImprovedEuler *improvedEuler;
    RungeKutta *rungeKutta;

private slots:
    void on_Solution_creator_clicked();

    void on_LTE_graph_clicked();

    void on_GTE_graph_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
