//
// Created by jiahao on 22-8-9.
//

#include <gtest/gtest.h>
#include "../analytic/vanilla_option.h"


TEST(TestVanillaOption, TestCall){
    double spot = 100;
    double strike = 100;
    double vol = 0.3;
    double r = 0.025;
    double q = 0.;
    double r_delivery = 0.0252;
    double tau = 1;
    double tau_delivery = 1.02;
    auto option_type = OptionType::Call;
    double pv = vanilla_pricer::price(spot, strike, vol, r, q, tau, r_delivery, tau_delivery, option_type);
    EXPECT_NEAR(pv, 13.0422195, 1e-6);
}
