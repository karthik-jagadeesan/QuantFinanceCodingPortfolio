// FX_EQ1_source.cpp

#include "FX.h"
#include "matrix.h"
#include <cmath>

#include <algorithm>


using namespace std;

result_data FX::evaluate_data_and_premium() const
{
	double dtau, alpha, k;

	vector<double> t, tau, S, x;

	matrix<double> u, v;

	matrix_resize(u, N, M);

	matrix_resize(v, N, M);

	// Therefore, both the matrices u, v are resized to N by M

	// Now, let us resize the vectors t, tau, S and x:

	t.resize(M);
	tau.resize(M);

	S.resize(N);
	x.resize(N);

	dtau = dt * (0.5*sigma*sigma);
	alpha = dtau / (dx*dx);
	k = r / (0.5*sigma*sigma);

	double xmin = -1;
	double xmax = +1;


	// STEP 2: SETUP MESH (x and tau grids)

	for (int i = 0; i < N; i++)
	{
		x[i] = xmin + i*dx;
		S[i] = K*exp(x[i]);
	}

	for (int j = 0; j < M; j++)
	{
		t[j] = j*dt;
		tau[j] = (T - t[j]) / (0.5*sigma*sigma);
	}

	// STEP 3: SETUP INITIAL CONDITION

	for (int i = 0; i < N; i++)
	{
		u[i][0] = max(exp(0.5*(k + 1)*x[i]) - exp(0.5*(k - 1)*x[i]), 0.0);
	}

	// STEP 4: SETUP BOUNDARY CONDITIONS

	for (int j = 1; j < M; j++)
	{
		u[0][j] = 0.0;
		u[N - 1][j] = u[N - 1][0];
	}

	// STEP 5: COMPUTE FORWARD DIFFERENCES

	for (int j = 0; j < M - 1; j++)
	{
		for (int i = 1; i < N - 1; i++)
		{
			u[i][j + 1] = alpha*u[i + 1][j] + (1 - 2 * alpha)*u[i][j] + alpha*u[i - 1][j];
		}
	}

	// STEP 6: TRANSFORM SOLUTION FROM X TO S COORDINATES (u and v)

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			v[i][j] = pow(K, (0.5*(1 + k)))*pow(S[i], (0.5*(1 - k)))*exp(1.0 / 8.0*(k + 1)*(k + 1)*sigma*sigma*(T - t[i]))*u[i][j];
		}
	}

	result_data result(alpha, dtau, k, x, S, t, tau, u, v);

	return result;

}
