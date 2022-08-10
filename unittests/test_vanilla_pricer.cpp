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
    double pv = vanilla_pricer::price(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(pv, 13.0422195, 1e-6);

    double delta = vanilla_pricer::delta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(delta, 0.591831, 1e-6);

    double gamma = vanilla_pricer::gamma(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(gamma, 0.0129318, 1e-6);

    double theta = vanilla_pricer::theta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(theta, -6.970247, 1e-6);

    double vega = vanilla_pricer::vega(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(vega, 38.795545, 1e-6);

    double rho = vanilla_pricer::rho(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(rho, 45.880127, 1e-6);

    double phi = vanilla_pricer::phi(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(phi, -59.183191, 1e-6);
}


TEST(TestVanillaOption, TestPut){
    double spot = 100;
    double strike = 100;
    double vol = 0.3;
    double r = 0.025;
    double q = 0.;
    double r_delivery = 0.0252;
    double tau = 1;
    double tau_delivery = 1.02;
    auto option_type = OptionType::Put;
    double pv = vanilla_pricer::price(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(pv, 10.574948, 1e-6);

    double delta = vanilla_pricer::delta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(delta, -0.407464, 1e-6);

    double gamma = vanilla_pricer::gamma(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(gamma, 0.0129318, 1e-6);

    double theta = vanilla_pricer::theta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(theta, -4.534182, 1e-6);

    double vega = vanilla_pricer::vega(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(vega, 38.795545, 1e-6);

    double rho = vanilla_pricer::rho(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(rho, -51.532880, 1e-6);

    double phi = vanilla_pricer::phi(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(phi, 40.746433, 1e-6);
}
