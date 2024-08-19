#include <iostream>
#include "payoff_double_digital.h"

int main(int argc, char **argv) {
  double D = 10.0;  // Lower strike
  double U = 20.0;  // Upper strike

  PayOffDoubleDigital pay(U, D);  // Create the double digital payoff

  // Output the payoff for various spot prices
  std::cout << "Spot = 5.0 : " << pay(5.0) << std::endl;
  std::cout << "Spot = 15.0: " << pay(15.0) << std::endl;
  std::cout << "Spot = 25.0: " << pay(25.0) << std::endl;

  return 0;
}
