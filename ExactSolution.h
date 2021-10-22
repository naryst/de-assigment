//
// Created by nikita on 22.10.2021.
//

#ifndef UNTITLED_EXACTSOLUTION_H
#define UNTITLED_EXACTSOLUTION_H
#include "Grid.h"
#include "Equation.h"

class ExactSolution : public Grid, public Equation{
public:
    static double getConst(double x, double y);

    double y(double x, double c);

    ExactSolution(double x0, double y0, double X, double h);

    void GetSolutions();
};


#endif //UNTITLED_EXACTSOLUTION_H
