// IR2_source.cpp

#include "IR.h"
#include "random.h"
#include "matrix.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

IR_results IR::run_LIBOR_simulations() const
{
	matrix<double> L; // forward rates
	matrix_resize(L, N + 1, N + 1);
	matrix<double> D; // discount factors
	matrix_resize(D, N + 2, N + 2);

	vector<double> dW(N + 1); // discount factors
	vector<double> V(N + 2); // caplet payoff
	vector<double> Vprime(N + 2); // numeraire-rebased caplet payoff
	vector<double> Vcap(M); // simulation payoff

	// Composing the SampleBoxMuller class:

	SampleBoxMuller normal;
	
	double df_prod = 1.0;
	double drift_sum = 0.0;

	double sumcap = 0.0;
	double payoff = 0.0;

	// STEP 2: INITIALISE SPOT RATES

	L[0][0] = 0.05;
	L[1][0] = 0.05;
	L[2][0] = 0.05;
	L[3][0] = 0.05;
	L[4][0] = 0.05;

	// start main MC loop

	for (int nsim = 0; nsim < M; ++nsim)
	{

		// STEP 3: BROWNIAN MOTION INCREMENTS

		dW[1] = sqrt(dT)*(normal());
		dW[2] = sqrt(dT)*(normal());
		dW[3] = sqrt(dT)*(normal());
		dW[4] = sqrt(dT)*(normal());

		// STEP 4: COMPUTE FORWARD RATES TABLEAU

		for (int n = 0; n < N; ++n)
		{
			for (int i = n + 1; i < N + 1; ++i)
			{
				drift_sum = 0.0;
				for (int k = i + 1; k < N + 1; ++k)
				{
					drift_sum += (alpha*sigma*L[k][n]) / (1 + alpha*L[k][n]);
				}
				L[i][n + 1] = L[i][n] * exp((-drift_sum*sigma - 0.5*sigma*sigma)*dT 
								+ sigma*dW[n + 1]);
				// cout <<�L: i = � << i <<�, n+1 = � << n+1 <<�, = � << L[i][n+1] << �\n�;
			}
		}

		// STEP 5: COMPUTE DISCOUNT RATES TABLEAU

		for (int n = 0; n < N + 1; ++n)
		{
			for (int i = n + 1; i < N + 2; ++i)
			{
				df_prod = 1.0;
				for (int k = n; k < i; k++)
				{
					df_prod *= 1 / (1 + alpha*L[k][n]);
				}
				D[i][n] = df_prod;
				// cout <<�D: i = � << i <<�, n = � << n <<�, D[i][n] = � 
				//		<< D[i][n] << �\n�;
			}
		}

		// STEP 6: COMPUTE CAPLETS

		double diff;

		diff = L[0][0] - K;
		V[1] = max(diff, 0.0);

		diff = L[1][1] - K;
		V[2] = max(diff, 0.0);

		diff = L[2][2] - K;
		V[3] = max(diff, 0.0);

		diff = L[3][3] - K;
		V[4] = max(diff, 0.0);

		diff = L[4][4] - K;
		V[5] = max(diff, 0.0);

		// STEP 7: COMPUTE NUMERAIRE-REBASED CAPLETS

		Vprime[1] = V[1] * D[1][0] / D[5][0];
		Vprime[2] = V[2] * D[2][1] / D[5][1];
		Vprime[3] = V[3] * D[3][2] / D[5][2];
		Vprime[4] = V[4] * D[4][3] / D[5][3];
		Vprime[5] = V[5] * D[5][4] / D[5][4];

		// STEP 8: COMPUTE CAP PAYOFF

		Vcap[nsim] = Vprime[1] + Vprime[2] + Vprime[3] + Vprime[4] + Vprime[5];
	}
	// end main MC loop

	// STEP 9: COMPUTE DISCOUNTED EXPECTED PAYOFF

	sumcap = 0.0;

	for (int nsim = 0; nsim < M; ++nsim)
	{
		sumcap += Vcap[nsim];
	}

	payoff = D[N + 1][0] * sumcap / M;

	IR_results results(Vcap, payoff);

	return results;
}
