//
// Created by Jiahao FENG on 9/8/2022.
//

#include "digital_option.h"

namespace digital_pricer{
    double price(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery
    ){
        double d2 = funcs::calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau -r_delivery * tau_delivery);
        if(option_type == OptionType::Call)
            return df * exp(-r * tau) * funcs::normal_cdf(d2);
        else
            return df * exp(-r * tau) * (1 - funcs::normal_cdf(d2));
    }

    double delta(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery
    ){
        double d2 = funcs::calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau -r_delivery * tau_delivery);
        double delta_ = df * exp(-r * tau) * funcs::normal_pdf(d2) / (vol * spot * sqrt(tau));
        if(option_type == OptionType::Call)
            return delta_;
        else
            return -delta_;
    }

    double gamma(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery
    ){
        double d1 = funcs::calc_d1(spot, strike, r, q, vol, tau);
        double d2 = funcs::calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau -r_delivery * tau_delivery);
        double gamma_ = -df * exp(-r * tau) * d1 * funcs::normal_pdf(d2) /
                (pow(vol * spot, 2.) * sqrt(tau));
        if(option_type == OptionType::Call)
            return gamma_;
        else
            return -gamma_;
    }

    double vega(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery
    ){
        double d2 = funcs::calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau -r_delivery * tau_delivery);
        double vega_ = -df * exp(-r * tau) * funcs::normal_pdf(d2) * (sqrt(tau) + d2 / vol);
        if(option_type == OptionType::Call)
            return vega_;
        else
            return -vega_;
    }
}
