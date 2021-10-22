//
// Created by nikita on 22.10.2021.
//

#include "ExactSolution.h"
#include <bits/stdc++.h>


void ExactSolution::GetSolutions() {
    xs.push_back(x0);
    ys.push_back(y0);
    double currentX = x0+h;
    double C = getConst(x0, y0);
    while (currentX < X){
        this->xs.push_back(currentX);
        this->ys.push_back(y(currentX, C));
        currentX += h;
    }
}

double ExactSolution::y(double x, double c) {
    return pow(M_E, x*x/2)/ sqrt(c + pow(M_E, x*x));
}

double ExactSolution::getConst(double x, double y) {
    return pow(M_E, x*x)/(y*y) - pow(M_E, x*x);
}

ExactSolution::ExactSolution(double x0, double y0, double X, double h)
        : Equation(x0, y0, X, h){}