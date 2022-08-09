//
// Created by jiahao on 22-8-9.
//

#include <cmath>
#include "funcs.h"

namespace funcs{
    double normal_cdf(double x){
        return std::erfc(-x / sqrt(2)) / 2;
    }

    double normal_pdf(double x){
        return 1 / sqrt(2 * M_PI) * exp(-x * x / 2);
    }
}