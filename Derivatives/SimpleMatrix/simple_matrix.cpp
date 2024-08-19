#ifndef __SIMPLE_MATRIX_CPP
#define __SIMPLE_MATRIX_CPP

#include "simple_matrix.h"

// Default constructor
template <typename Type>
SimpleMatrix<Type>::SimpleMatrix() {
  // No need for implementation, as the vector "mat" 
  // will create the necessary storage
}

// Constructor with row/col specification and default values
template <typename Type>
SimpleMatrix<Type>::SimpleMatrix(const int& rows, const int& cols, 
                                 const Type& val) {
  for (int i=0; i<rows; i++) {
    std::vector<Type> col_vec (cols, val);
    mat.push_back(col_vec);
  }
}

// Copy constructor
template <typename Type>
SimpleMatrix<Type>::SimpleMatrix(const SimpleMatrix<Type>& _rhs) {
  mat = _rhs.get_mat();
}

// Overloaded assignment operator
template <typename Type>
SimpleMatrix<Type>& SimpleMatrix<Type>::operator= (const SimpleMatrix<Type>& _rhs) 
{
  if (this == &_rhs) return *this;  // Handling assignment to self
  mat = _rhs.get_mat();
  return *this;
}

// Destructor
template <typename Type>
SimpleMatrix<Type>::~SimpleMatrix() {
  // No need for implementation, as there is no 
  // manual dynamic memory allocation
}

// Matrix access method, via copying
template <typename Type>
std::vector<std::vector<Type> > SimpleMatrix<Type>::get_mat() const {
  return mat;
}

// Matrix access method, via row and column index
template <typename Type>
Type& SimpleMatrix<Type>::value(const int& row, const int& col) {
  return mat[row][col];
}

#endif
