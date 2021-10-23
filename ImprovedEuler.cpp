//
// Created by nikita on 23.10.2021.
//

#include "ImprovedEuler.h"

ImprovedEuler::ImprovedEuler(double x0, double y0, double X, double h)
    : NumericMethod(x0, y0, X, h){}

void ImprovedEuler::GetSolutions(){
    xs.clear();
    ys.clear();
    xs.push_back(x0);
    ys.push_back(y0);
    double currentX = x0 + h;
    while (currentX < X) {
        double prevVal = *ys.rbegin();
        xs.push_back(currentX);
        double z_n = prevVal + h * yDerivative(currentX - h, prevVal);
        double nextTerm = *ys.rbegin() + h * (yDerivative(currentX - h, prevVal)
                                              + yDerivative(currentX, z_n))/2;
        ys.push_back(nextTerm);
        currentX += h;
    }
}
