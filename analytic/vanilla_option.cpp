//
// Created by jiahao on 22-8-9.
//

#include "funcs.h"
#include "vanilla_option.h"

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
        double d1 = funcs::calc_d1(spot, strike, r, q, vol, tau);
        double d2 = funcs::calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau) * exp(-r_delivery * tau_delivery);
        if(option_type == OptionType::Call)
            return df * (spot * exp(-q * tau) * funcs::normal_cdf(d1) -
                         strike * exp(-r * tau) * funcs::normal_cdf(d2));
        else
            return df * (-spot * exp(-q * tau) * funcs::normal_cdf(-d1) +
                         strike * exp(-r * tau) * funcs::normal_cdf(-d2));
    }
}