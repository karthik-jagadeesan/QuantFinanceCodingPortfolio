#include <iostream>
#include <Eigen/Dense>

int main() {
  // Declare and initialise two 3D vectors
  Eigen::Vector3d r(10,20,30);
  Eigen::Vector3d s(40,50,60);

  // Apply the 'dot' and 'cross' products 
  std::cout << "r . s =\n" << r.dot(s) << std::endl;
  std::cout << "r x s =\n" << r.cross(s) << std::endl;
}
