// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

// Definition of a simple matrix using vectors:

template <class T> 
using matrix = std::vector<std::vector<T>>;

using custom_size_t = unsigned int;

template <class T>

void matrix_resize(T& u, custom_size_t N, custom_size_t M)
{
	// to make number of rows = N

	u.resize(N);

	// to make number of columns = M

	for (auto& row : u)
		row.resize(M);
}

#endif