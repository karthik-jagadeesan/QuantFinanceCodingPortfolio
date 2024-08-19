#include "black_scholes.h"

// This uses the forward difference approximation to calculate the Delta of a call option
double call_delta_fdm(const double S, const double K, const double r, const double v, const double T, const double delta_S) {
  return (call_price(S + delta_S, K, r, v, T) - call_price(S, K, r, v, T))/delta_S;
}

// This uses the centred difference approximation to calculate the Gamma of a call option
double call_gamma_fdm(const double S, const double K, const double r, const double v, const double T, const double delta_S) {
  return (call_price(S + delta_S, K, r, v, T) - 2*call_price(S, K, r, v, T) + call_price(S - delta_S, K, r, v, T))/(delta_S*delta_S);
}

int main(int argc, char **argv) {
  // First we create the parameter list
  double S = 100.0;        // Option price
  double delta_S = 0.001;  // Option price increment
  double K = 100.0;        // Strike price
  double r = 0.05;         // Risk-free rate (5%)
  double v = 0.2;          // Volatility of the underlying (20%)
  double T = 1.0;          // One year until expiry
    
  // Then we calculate the Delta and the Gamma for the call
  double call_delta_f = call_delta_fdm(S, K, r, v, T, delta_S);
  double call_gamma_f = call_gamma_fdm(S, K, r, v, T, delta_S);

  // Finally we output the parameters and greeks
  std::cout << "Underlying:        " << S << std::endl;
  std::cout << "Delta underlying:  " << delta_S << std::endl;
  std::cout << "Strike:            " << K << std::endl;
  std::cout << "Risk-Free Rate:    " << r << std::endl;
  std::cout << "Volatility:        " << v << std::endl;
  std::cout << "Maturity:          " << T << std::endl << std::endl;

  std::cout << "Call Delta:        " << call_delta_f << std::endl;
  std::cout << "Call Gamma:        " << call_gamma_f << std::endl;
}
