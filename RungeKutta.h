//
// Created by nikita on 23.10.2021.
//

#ifndef UNTITLED_RUNGEKUTTA_H
#define UNTITLED_RUNGEKUTTA_H
#include "NumericMethod.h"

class RungeKutta : public NumericMethod{
public:
    RungeKutta(double x0, double y0, double X, double h);
    void GetSolutions() override;
};


#endif //UNTITLED_RUNGEKUTTA_H
