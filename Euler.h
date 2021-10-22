//
// Created by nikita on 23.10.2021.
//

#ifndef UNTITLED_EULER_H
#define UNTITLED_EULER_H


#include "NumericMethod.h"

class Euler : public NumericMethod {
public:
    Euler(double x0, double y0, double X, double h);
    void GetSolutions() override;
};


#endif //UNTITLED_EULER_H
