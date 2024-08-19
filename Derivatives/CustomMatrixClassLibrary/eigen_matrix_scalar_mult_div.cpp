#include <iostream>
#include <Eigen/Dense>

int main() {
  // Define a 3x3 matrix and initialise
  Eigen::Matrix3d p;
  p << 1, 2, 3,
       4, 5, 6,
       7, 8, 9;

  // Multiply and divide by a scalar
  std::cout << "p * 3.14159 =\n" << p * 3.14159 << std::endl;
  std::cout << "p / 2.71828 =\n" << p / 2.71828 << std::endl; 
}
