#include <iostream>
#include <Eigen/Dense>

int main() {
  // Define two matrices, both 3x3
  Eigen::Matrix3d p;
  Eigen::Matrix3d q;

  // Define two three-dimensional vectors
  // The constructor provides initialisation
  Eigen::Vector3d r(1,2,3);
  Eigen::Vector3d s(4,5,6);

  // Use the << operator to fill the matrices
  p << 1, 2, 3,
       4, 5, 6,
       7, 8, 9;
  q << 10, 11, 12,
       13, 14, 15,
       16, 17, 18;

  // Output arithmetic operations for matrices
  std::cout << "p+q=\n" << p + q << std::endl;
  std::cout << "p-q=\n" << p - q << std::endl;

  // Output arithmetic operations for vectors
  std::cout << "r+s=\n" << r + s << std::endl;
  std::cout << "r-s=\n" << r - s << std::endl;
}
