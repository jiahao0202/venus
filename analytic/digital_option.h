//
// Created by Jiahao FENG on 9/8/2022.
//

#ifndef VENUS_DIGITAL_OPTION_H
#define VENUS_DIGITAL_OPTION_H

#include <iostream>
#include "funcs.h"
#include "../utils/enums.h"

namespace digital_pricer{
    double price(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery);

    double delta(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery);

    double gamma(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery);

    double theta(double spot,
                 double strike,
                 double vol,
                 double r,
                 double q,
                 double tau,
                 OptionType option_type,
                 double r_delivery,
                 double tau_delivery);

    double vega(double spot,
                double strike,
                double vol,
                double r,
                double q,
                double tau,
                OptionType option_type,
                double r_delivery,
                double tau_delivery);

    double rho(double spot,
               double strike,
               double vol,
               double r,
               double q,
               double tau,
               OptionType option_type,
               double r_delivery,
               double tau_delivery);

    double phi(double spot,
               double strike,
               double vol,
               double r,
               double q,
               double tau,
               OptionType option_type,
               double r_delivery,
               double tau_delivery);
}

#endif //VENUS_DIGITAL_OPTION_H
