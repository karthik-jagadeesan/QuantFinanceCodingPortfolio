#ifndef __MAIN_CPP
#define __MAIN_CPP

#include "black_scholes.h"
#include "interval_bisection.h"
#include <iostream>

int main(int argc, char **argv) {

    // First we create the parameter list
    double S = 100.0;  // Underlying spot price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate (5%)
    double T = 1.0;    // One year until expiry
    double C_M = 10.5; // Option market price

    // Create the Black-Scholes Call functor
    BlackScholesCall bsc(S, K, r, T);

    // Interval Bisection parameters
    double low_vol = 0.05;
    double high_vol = 0.35;
    double episilon = 0.001;

    // Calculate the implied volatility
    double sigma = interval_bisection(C_M, low_vol, high_vol, episilon, bsc);

    // Output the values
    std::cout << "Implied Vol: " << sigma << std::endl;

    return 0;
}

#endif
