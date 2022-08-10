//
// Created by Jiahao FENG on 10/8/2022.
//

#include <gtest/gtest.h>
#include "../analytic/digital_option.h"


TEST(TestDigitalOption, TestCall){
    double spot = 100;
    double strike = 100;
    double vol = 0.3;
    double r = 0.025;
    double q = 0.;
    double r_delivery = 0.0252;
    double tau = 1;
    double tau_delivery = 1.02;
    auto option_type = OptionType::Call;
    double pv = digital_pricer::price(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(pv, 0.461409, 1e-6);

    double delta = digital_pricer::delta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(delta, 0.012931, 1e-6);

    double gamma = digital_pricer::gamma(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(gamma, -0.0001005, 1e-6);

    double theta = digital_pricer::theta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(theta, 0.024559, 1e-6);

    double vega = digital_pricer::vega(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(vega, -0.301743, 1e-6);

    double rho = digital_pricer::rho(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(rho, 0.822546, 1e-6);

    double phi = digital_pricer::phi(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(phi, -1.293184, 1e-6);
}


TEST(TestDigitalOption, TestPut){
    double spot = 100;
    double strike = 100;
    double vol = 0.3;
    double r = 0.025;
    double q = 0.;
    double r_delivery = 0.0252;
    double tau = 1;
    double tau_delivery = 1.02;
    auto option_type = OptionType::Put;
    double pv = digital_pricer::price(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(pv, 0.513213, 1e-6);

    double delta = digital_pricer::delta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(delta, -0.012931, 1e-6);

    double gamma = digital_pricer::gamma(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(gamma, 0.0001005, 1e-6);

    double theta = digital_pricer::theta(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(theta, 1.13968e-06, 1e-6);

    double vega = digital_pricer::vega(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(vega, 0.301743, 1e-6);

    double rho = digital_pricer::rho(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(rho, -1.816662, 1e-6);

    double phi = digital_pricer::phi(spot, strike, vol, r, q, tau, option_type, r_delivery, tau_delivery);
    EXPECT_NEAR(phi, 1.29318484, 1e-6);
}
