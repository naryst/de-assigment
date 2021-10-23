//
// Created by nikita on 23.10.2021.
//

#include "RungeKutta.h"

RungeKutta::RungeKutta(double x0, double y0, double X, double h): NumericMethod(x0, y0, X, h){}

void RungeKutta::GetSolutions() {
    ys.clear();
    xs.clear();
    xs.push_back(x0);
    ys.push_back(y0);
    double currentX = x0 + h;
    while (currentX < X){
        double prevVal = *ys.rbegin();
        double k1 = yDerivative(currentX-h, prevVal);
        double k2 = yDerivative(currentX - h/2, prevVal + h/2*k1);
        double k3 = yDerivative(currentX - h/2, prevVal + h/2*k2);
        double k4 = yDerivative(currentX, prevVal + h*k3);
        xs.push_back(currentX);
        ys.push_back(prevVal + h * (k1/6 + k2/3 + k3/3 + k4/6));
        currentX += h;
    }
}
