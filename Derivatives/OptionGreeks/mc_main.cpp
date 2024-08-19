#include "black_scholes.h"

// Pricing a European vanilla call option with a Monte Carlo method
// Create three separate paths, each with either an increment, non-
// increment or decrement based on delta_S, the stock path parameter
void monte_carlo_call_price(const int num_sims, 
                            const double S, const double K, const double r, 
                            const double v, const double T, const double delta_S, 
                            double& price_Sp, double& price_S, double& price_Sm) {

  // Since we wish to use the same Gaussian random draws for each path, it is
  // necessary to create three separated adjusted stock paths for each 
  // increment/decrement of the asset
  double Sp_adjust = (S+delta_S) * exp(T*(r-0.5*v*v));
  double S_adjust = S * exp(T*(r-0.5*v*v));
  double Sm_adjust = (S-delta_S) * exp(T*(r-0.5*v*v));

  // These will store all three 'current' prices as the Monte Carlo
  // algorithm is carried out
  double Sp_cur = 0.0;
  double S_cur = 0.0;
  double Sm_cur = 0.0;

  // There are three separate pay-off sums for the final price
  double payoff_sum_p = 0.0;
  double payoff_sum = 0.0;
  double payoff_sum_m = 0.0;

  // Loop over the number of simulations
  for (int i=0; i<num_sims; i++) {
    double gauss_bm = gaussian_box_muller(); // Random gaussian draw

    // Adjust three stock paths 
    double expgauss = exp(sqrt(v*v*T)*gauss_bm);  // Precalculate
    Sp_cur = Sp_adjust * expgauss;
    S_cur = S_adjust * expgauss;
    Sm_cur = Sm_adjust * expgauss;

    // Calculate the continual pay-off sum for each increment/decrement
    payoff_sum_p += std::max(Sp_cur - K, 0.0);
    payoff_sum += std::max(S_cur - K, 0.0);
    payoff_sum_m += std::max(Sm_cur - K, 0.0);
  }

  // There are three separate prices
  price_Sp = (payoff_sum_p / static_cast<double>(num_sims)) * exp(-r*T);
  price_S = (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);
  price_Sm = (payoff_sum_m / static_cast<double>(num_sims)) * exp(-r*T);
}

double call_delta_mc(const int num_sims, const double S, const double K, const double r, const double v, const double T, const double delta_S) {
  // These values will be populated via the monte_carlo_call_price function.
  // They represent the incremented Sp (S+delta_S), non-incremented S (S) and
  // decremented Sm (S-delta_S) prices.
  double price_Sp = 0.0;
  double price_S = 0.0;
  double price_Sm = 0.0;
  
  // Call the Monte Carlo pricer for each of the three stock paths
  // (We only need two for the Delta)
  monte_carlo_call_price(num_sims, S, K, r, v, T, delta_S, price_Sp, price_S, price_Sm);
  return (price_Sp - price_S)/delta_S;
}

double call_gamma_mc(const int num_sims, const double S, const double K, const double r, const double v, const double T, const double delta_S) {
  // These values will be populated via the monte_carlo_call_price function.
  // They represent the incremented Sp (S+delta_S), non-incremented S (S) and
  // decremented Sm (S-delta_S) prices.
  double price_Sp = 0.0;
  double price_S = 0.0;
  double price_Sm = 0.0;

  // Call the Monte Carlo pricer for each of the three stock paths
  // (We need all three for the Gamma) 
  monte_carlo_call_price(num_sims, S, K, r, v, T, delta_S, price_Sp, price_S, price_Sm);
  return (price_Sp - 2*price_S + price_Sm)/(delta_S*delta_S);
}

int main(int argc, char **argv) {
  // First we create the parameter list
  double S = 100.0;            // Option price
  double delta_S = 0.001;      // Option price increment
  double K = 100.0;            // Strike price
  double r = 0.05;             // Risk-free rate (5%)
  double v = 0.2;              // Volatility of the underlying (20%)
  double T = 1.0;              // One year until expiry
  int num_sims = 10000000;    // Number of simulations to carry out for Monte Carlo    

  // Then we calculate the Delta and the Gamma for the call
  double call_delta_m = call_delta_mc(num_sims, S, K, r, v, T, delta_S);
  double call_gamma_m = call_gamma_mc(num_sims, S, K, r, v, T, delta_S);

  // Finally we output the parameters and greeks
  std::cout << "Number of sims:    " << num_sims << std::endl;
  std::cout << "Underlying:        " << S << std::endl;
  std::cout << "Delta underlying:  " << delta_S << std::endl;
  std::cout << "Strike:            " << K << std::endl;
  std::cout << "Risk-Free Rate:    " << r << std::endl;
  std::cout << "Volatility:        " << v << std::endl;
  std::cout << "Maturity:          " << T << std::endl << std::endl;

  std::cout << "Call Delta:        " << call_delta_m << std::endl;
  std::cout << "Call Gamma:        " << call_gamma_m << std::endl;
}
