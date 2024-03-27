// FX_print.cpp

#include "FX.h"

#include <iostream>
#include <iomanip>

using namespace std;

ostream& operator << (ostream& os, const result_data& rs)
{
	auto M(0), N(0);

	N = rs.u.size();

	if (N)
		M = rs.u[0].size();

	os << setw(10) << " dtau = " << rs.dtau << "\n";
	os << setw(10) << " alpha = " << rs.alpha << "\n";
	os << setw(10) << " k = " << rs.k << "\n";

	os << "\n.....x and tau grids .......................\n\n";

	for (int i = 0; i < N; i++)
	{
		os << setw(5) << "x " << rs.x[i] << "\n";
		os << setw(5) << "S " << rs.S[i] << "\n";
	}

	for (int j = 0; j < M; j++)
	{
		os << setw(5) << "t " << rs.t[j] << "\n";
		os << setw(5) << "tau " << rs.tau[j] << "\n";
	}

	os << "\n.....init cond........................\n\n";

	// STEP 3: SETUP INITIAL CONDITION

	for (int i = 0; i < N; i++)
	{
		os << setw(5) << "i " << i << setw(5) << "u " << rs.u[i][0] << "\n";
	}

	os << "\n.....bcs........................\n\n";

	// STEP 4: SETUP BOUNDARY CONDITIONS

	for (int j = 1; j < M; j++)
	{
		os << setw(5) << "j " << j << setw(12) << "u[0][j] " << rs.u[0][j] << "\n";
		os << setw(5) << "j " << j << setw(12) << "u[N-1][j] " << rs.u[N - 1][j] << "\n";
	}

	os << "\n.....u and v.......................\n\n";

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			os << setw(5) << "i= " << i << ", j= " << j << setw(11) << " v[i][j] " << rs.v[i][j] << "\n";
		}
	}

	os << "\n premium =  " << rs.v[N/2][M - 1] << "\n"; // for strike = 75

	return os;
}

