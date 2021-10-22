//
// Created by nikita on 23.10.2021.
//

#ifndef UNTITLED_NUMERICMETHOD_H
#define UNTITLED_NUMERICMETHOD_H

#include "Grid.h"
#include "Equation.h"

class NumericMethod: public Grid, public Equation {
public:
    NumericMethod(double x0, double y0, double X, double h);
    virtual void GetSolutions() = 0;
};


#endif //UNTITLED_NUMERICMETHOD_H
