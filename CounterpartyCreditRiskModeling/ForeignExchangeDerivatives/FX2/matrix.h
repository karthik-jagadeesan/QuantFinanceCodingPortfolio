// matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef>


// Definition of a simple matrix using vectors:

template <class T> 
using matrix = std::vector<std::vector<T>>;

template <class T>
inline void 
matrix_resize(T& u, size_t N, size_t M)
{
	// to make number of rows = N

	u.resize(N);

	// to make number of columns = M

	for (auto& row : u)
		row.resize(M);
}

#endif