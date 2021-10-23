#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QtCharts>
#include <bits/stdc++.h>

using namespace std;

#include "Grid.h"
#include "Equation.h"
#include "ExactSolution.h"
#include "NumericMethod.h"
#include "Euler.h"
#include "ImprovedEuler.h"
#include "RungeKutta.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.chart->setTitle("Solutions Graph");
    w.chartView->setRenderHint(QPainter::Antialiasing);
    w.show();
    return a.exec();
}
