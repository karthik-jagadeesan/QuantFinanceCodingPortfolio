#include <iostream>
#include "simple_matrix.h"

int main(int argc, char **argv) {
  // Create an empty SimpleMatrix of type double
  SimpleMatrix<double> sm(4, 4, 0.0);

  // Output values of the SimpleMatrix
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      std::cout << sm.value(i,j) << "\t";
    }
    std::cout << std::endl;
  }

  return 0;
}
