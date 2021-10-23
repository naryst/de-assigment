//
// Created by nikita on 23.10.2021.
//

#include "Euler.h"

Euler::Euler(double x0, double y0, double X, double h) : NumericMethod(x0, y0, X, h) {}

void Euler::GetSolutions(){
    xs.clear();
    ys.clear();
    xs.push_back(x0);
    ys.push_back(y0);
    double currentX = x0 + h;
    while (currentX < X) {
        this->xs.push_back(currentX);
        double nextTerm = *this->ys.rbegin() + h * yDerivative(currentX - h, *this->ys.rbegin());
        this->ys.push_back(nextTerm);
        currentX += h;
    }
}