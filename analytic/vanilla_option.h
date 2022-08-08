//
// Created by Jiahao FENG on 8/8/2022.
//

#ifndef PYBIND_CPP_VANILLA_OPTION_H
#define PYBIND_CPP_VANILLA_OPTION_H

#include <iostream>
#include <gsl/gsl_cdf.h>

#include "funcs.h"
#include "../utils/enums.h"

namespace vanilla_pricer{
    double price(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 double r_delivery,
                 double tau_delivery,
                 OptionType option_type){
        double d1 = calc_d1(spot, strike, r, q, vol, tau);
        double d2 = calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau) * exp(-r_delivery * tau_delivery);
        if(option_type == OptionType::Call)
            return df * (spot * exp(-q * tau) * gsl_cdf_ugaussian_Q(d1) -
                         strike * exp(-r * tau) * gsl_cdf_ugaussian_Q(d2));
        else
            return df * (-spot * exp(-q * tau) * gsl_cdf_ugaussian_Q(-d1) +
                         strike * exp(-r * tau) * gsl_cdf_ugaussian_Q(-d2));
    }
}

#endif //PYBIND_CPP_VANILLA_OPTION_H
