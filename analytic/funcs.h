//
// Created by Jiahao FENG on 8/8/2022.
//

#ifndef PYBIND_CPP_FUNCS_H
#define PYBIND_CPP_FUNCS_H

#include <cmath>

namespace funcs{

    double normal_cdf(double x);

    double normal_pdf(double x);

    inline double calc_d1(double spot,
                     double strike,
                     double r,
                     double q,
                     double vol,
                     double tau
                     ){
        return (log(spot / strike) + (r - q + .5 * vol * vol) * tau) / (vol * sqrt(tau));
    }

    inline double calc_d2(double spot,
                     double strike,
                     double r,
                     double q,
                     double vol,
                     double tau){
        return (log(spot / strike) + (r - q - .5 * vol * vol) * tau) / (vol * sqrt(tau));
    }
}

#endif //PYBIND_CPP_FUNCS_H
