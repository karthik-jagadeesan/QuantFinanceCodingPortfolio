#include <iostream>
#include <Eigen/Dense>

int main() {
  // Declare and initialise a 3D matrix
  Eigen::Matrix3d p;
  p << 1, 2, 3,
       4, 5, 6,
       7, 8, 9;

  // Output the reduction operations
  std::cout << "p.sum(): " << p.sum() << std::endl;
  std::cout << "p.prod(): " << p.prod() << std::endl;
  std::cout << "p.mean(): " << p.mean() << std::endl;
  std::cout << "p.minCoeff(): " << p.minCoeff() << std::endl;
  std::cout << "p.maxCoeff(): " << p.maxCoeff() << std::endl;
  std::cout << "p.trace(): " << p.trace() << std::endl;
}
