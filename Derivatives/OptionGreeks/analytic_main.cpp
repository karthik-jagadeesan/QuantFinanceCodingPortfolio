#include "black_scholes.h"

int main(int argc, char **argv) {
  // First we create the parameter list
  double S = 100.0;  // Option price
  double K = 100.0;  // Strike price
  double r = 0.05;   // Risk-free rate (5%)
  double v = 0.2;    // Volatility of the underlying (20%)
  double T = 1.0;    // One year until expiry

  // Then we calculate the call/put values and the Greeks
  double call = call_price(S, K, r, v, T);
  double call_delta_v = call_delta(S, K, r, v, T);
  double call_gamma_v = call_gamma(S, K, r, v, T);
  double call_vega_v = call_vega(S, K, r, v, T);
  double call_theta_v = call_theta(S, K, r, v, T);
  double call_rho_v = call_rho(S, K, r, v, T);

  double put = put_price(S, K, r, v, T);
  double put_delta_v = put_delta(S, K, r, v, T);
  double put_gamma_v = put_gamma(S, K, r, v, T);
  double put_vega_v = put_vega(S, K, r, v, T);
  double put_theta_v = put_theta(S, K, r, v, T);
  double put_rho_v = put_rho(S, K, r, v, T);

  // Finally we output the parameters and prices
  std::cout << "Underlying:      " << S << std::endl;
  std::cout << "Strike:          " << K << std::endl;
  std::cout << "Risk-Free Rate:  " << r << std::endl;
  std::cout << "Volatility:      " << v << std::endl;
  std::cout << "Maturity:        " << T << std::endl << std::endl;

  std::cout << "Call Price:      " << call << std::endl;
  std::cout << "Call Delta:      " << call_delta_v << std::endl;
  std::cout << "Call Gamma:      " << call_gamma_v << std::endl;
  std::cout << "Call Vega:       " << call_vega_v << std::endl;
  std::cout << "Call Theta:      " << call_theta_v << std::endl;
  std::cout << "Call Rho:        " << call_rho_v << std::endl << std::endl;

  std::cout << "Put Price:       " << put << std::endl;
  std::cout << "Put Delta:       " << put_delta_v << std::endl;
  std::cout << "Put Gamma:       " << put_gamma_v << std::endl;
  std::cout << "Put Vega:        " << put_vega_v << std::endl;
  std::cout << "Put Theta:       " << put_theta_v << std::endl;
  std::cout << "Put Rho:         " << put_rho_v << std::endl;

  return 0;
}
