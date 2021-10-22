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
#include "RungeKuta.h"

//class Grid{
//public:
//    vector<double> ys;
//    vector<double> xs;
//};

//class Equation{
//public:
//    double x0, y0, X, h;
//    double yDerivative(double x, double y){return x*y - x*y*y*y;}
//    Equation(double x0, double y0, double X, double h){
//        this->x0 = x0;
//        this->y0 = y0;
//        this->X = X;
//        this->h = h;
//    }
//};

//class ExactSolution : public Grid, public Equation{
//public:
//    static double getConst(double x, double y){
//        return pow(M_E, x*x)/(y*y) - pow(M_E, x*x);
//    }
//
//    double y(double x, double c){
//        return pow(M_E, x*x/2)/ sqrt(c + pow(M_E, x*x));
//    }
//
//    ExactSolution(double x0, double y0, double X, double h)
//            : Equation(x0, y0, X, h){}
//
//    void GetSolutions(){
//        xs.push_back(x0);
//        ys.push_back(y0);
//        double currentX = x0+h;
//        double C = getConst(x0, y0);
//        while (currentX < X){
//            this->xs.push_back(currentX);
//            this->ys.push_back(y(currentX, C));
//            currentX += h;
//        }
//    }
//};

//class NumericMethod : public Grid, public Equation {
//public:
//    NumericMethod(double x0, double y0, double X, double h)
//            : Equation(x0, y0, X, h) { }
//
//    virtual void GetSolutions() = 0;
//};

//class Euler : public NumericMethod {
//public:
//    Euler(double x0, double y0, double X, double h)
//            : NumericMethod(x0, y0, X, h) { }
//
//    void GetSolutions() override {
//        xs.push_back(x0);
//        ys.push_back(y0);
//        double currentX = x0 + h;
//        while (currentX < X) {
//            this->xs.push_back(currentX);
//            double nextTerm = *this->ys.rbegin() + h * yDerivative(currentX - h, *this->ys.rbegin());
//            this->ys.push_back(nextTerm);
//            currentX += h;
//        }
//    }
//};

//class ImprovedEuler : NumericMethod {
//
//};
//
//class RungeKuta : NumericMethod {
//
//};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    cout << "Enter the data for your de:\n";
    cout << "Enter y0:";
    double x0 = 0, y0 = 0.707, X = 7, h = 0.25;
//    cin>>y0;
//    cout<<"Enter x0:";
//    cin>>x0;
//    cout<<"Enter X:";
//    cin>>X;
//    cout<<"Enter h:";
//    cin>>h;
    MainWindow w;
    auto *exact = new ExactSolution(x0, y0, X, h);
    auto *euler = new Euler(x0, y0, X, h);
    exact->GetSolutions();
    euler->GetSolutions();
    for (int i = 0; i < exact->ys.size(); i++) {
        cout << exact->xs[i] << ' ' << exact->ys[i];
        w.ExactGraph->append(exact->xs[i], exact->ys[i]);
        w.EulerGraph->append(euler->xs[i], euler->ys[i]);
        cout << endl;
    }
    w.ExactGraph->setName("Exact Solution");
    w.EulerGraph->setName("Euler method Solution");
    w.chart->addSeries(w.ExactGraph);
    w.chart->addSeries(w.EulerGraph);
    w.chart->createDefaultAxes();
    w.chart->setTitle("Solutions Graph");
    w.chartView->setRenderHint(QPainter::Antialiasing);
    w.show();
    return a.exec();
}