//
// Created by Jiahao FENG on 8/8/2022.
//

#pragma once

#ifndef PYBIND_CPP_VANILLA_OPTION_H
#define PYBIND_CPP_VANILLA_OPTION_H

#include <iostream>
#include "funcs.h"
#include "../utils/enums.h"

namespace vanilla_pricer{
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

#endif //PYBIND_CPP_VANILLA_OPTION_H
