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
                 double r_delivery,
                 double tau_delivery,
                 OptionType option_type);
}

#endif //PYBIND_CPP_VANILLA_OPTION_H
