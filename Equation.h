//
// Created by nikita on 22.10.2021.
//

#ifndef UNTITLED_EQUATION_H
#define UNTITLED_EQUATION_H


class Equation {
public:
    double x0, y0, X, h;
    double yDerivative(double x, double y);
    Equation(double x0, double y0, double X, double h);
};


#endif //UNTITLED_EQUATION_H
