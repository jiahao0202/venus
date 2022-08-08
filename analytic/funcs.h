//
// Created by Jiahao FENG on 8/8/2022.
//

#ifndef PYBIND_CPP_FUNCS_H
#define PYBIND_CPP_FUNCS_H

#include <iostream>
#include <numeric>

namespace black{
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
