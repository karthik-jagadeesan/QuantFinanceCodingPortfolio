#include <iostream>
#include <Eigen/Dense>

int main() {
  // Declare a 3x3 matrix with random entries
  Eigen::Matrix3d p = Eigen::Matrix3d::Random(3,3);

  // Output the transpose of p
  std::cout << "p^T =\n" << p.transpose() << std::endl;

  // In-place transposition
  p.transposeInPlace();

  // Output the in-place transpose of p
  std::cout << "p^T =\n" << p << std::endl;
}
