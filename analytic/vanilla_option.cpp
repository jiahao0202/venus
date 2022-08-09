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
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery
    ){
        double d1 = funcs::calc_d1(spot, strike, r, q, vol, tau);
        double d2 = funcs::calc_d2(spot, strike, r, q, vol, tau);
        double df = exp(r * tau -r_delivery * tau_delivery);
        if(option_type == OptionType::Call)
            return df * (spot * exp(-q * tau) * funcs::normal_cdf(d1) -
                         strike * exp(-r * tau) * funcs::normal_cdf(d2));
        else
            return df * (-spot * exp(-q * tau) * funcs::normal_cdf(-d1) +
                         strike * exp(-r * tau) * funcs::normal_cdf(-d2));
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
        double d1 = funcs::calc_d1(spot, strike, r, q, vol, tau);
        double df = exp(r * tau - r_delivery * tau_delivery);
        if(option_type == OptionType::Call)
            return df * exp(-q * tau) * funcs::normal_cdf(d1);
        else
            return df * exp(-q * tau) * (funcs::normal_cdf(d1) - 1);
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
        double df = exp(r * tau - r_delivery * tau_delivery);
        return df * exp(-q * tau) * funcs::normal_pdf(d1) / (vol * spot * sqrt(tau));
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
        double d1 = funcs::calc_d1(spot, strike, r, q, vol, tau);
        double df = exp(r * tau - r_delivery * tau_delivery);
        return df * spot * sqrt(tau) * exp(-q * tau) * funcs::normal_pdf(d1);
    }

    double phi(double spot,
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
        double df = exp(r * tau - r_delivery * tau_delivery);
        if(option_type == OptionType::Call)
            return -df * tau * spot * exp(-q * tau) * funcs::normal_cdf(d1);
        else
            return df * tau * spot * exp(-q * tau) * funcs::normal_cdf(-d1);
    }

    double rho(double spot,
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
        double df = exp(r * tau - r_delivery * tau_delivery);
        double pv = price(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
        if(option_type == OptionType::Call)
            return df * tau * strike * exp(-r * tau) * funcs::normal_cdf(d2) + df * (tau - tau_delivery) * pv;
        else
            return -df * tau * strike * exp(-r * tau) * funcs::normal_cdf(-d2) + df * (tau - tau_delivery) * pv;
    }

    double theta(double spot,
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
        double df = exp(r * tau - r_delivery * tau_delivery);
        double pv = price(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
        double theta_ = 0.;
        if(option_type == OptionType::Call)
            theta_ = -vol * spot * exp(-q * tau) * funcs::normal_pdf(d1) / (2 * sqrt(tau)) +
                    q * spot * funcs::normal_cdf(d1) * exp(-q * tau) -
                    r * strike * exp(-r * tau) * funcs::normal_cdf(d2);
        else
            theta_ = -vol * spot * exp(-q * tau) * funcs::normal_pdf(-d1) / (2 * sqrt(tau)) -
                    q * spot * funcs::normal_cdf(-d1) * exp(-q * tau) +
                    r * strike * exp(-r * tau) * funcs::normal_cdf(-d2);
        return pv * (r_delivery - r) * tau + df * theta_;
    }
}