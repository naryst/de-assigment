//
// Created by nikita on 23.10.2021.
//

#ifndef UNTITLED_IMPROVEDEULER_H
#define UNTITLED_IMPROVEDEULER_H
#include "NumericMethod.h"

class ImprovedEuler : public NumericMethod{
public:
    ImprovedEuler(double x0, double y0, double X, double h);
    void GetSolutions();
};


#endif //UNTITLED_IMPROVEDEULER_H
