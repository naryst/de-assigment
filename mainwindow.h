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
    void on_Sulution_creator_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
