//
// Created by nikita on 22.10.2021.
//

#include "Equation.h"

double Equation::yDerivative(double x, double y) {
    return x*y - x*y*y*y;
}

Equation::Equation(double x0, double y0, double X, double h) {
    this->x0 = x0;
    this->y0 = y0;
    this->X = X;
    this->h = h;
}
