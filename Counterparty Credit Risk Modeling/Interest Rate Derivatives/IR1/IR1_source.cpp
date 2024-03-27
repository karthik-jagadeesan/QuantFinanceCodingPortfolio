// IR1_source.cpp

#include "IR.h"
#include "random.h"
#include "matrix.h"
#include <algorithm>
#include <iostream>

using namespace std;

IR_results IR::run_LIBOR_simulations() const
{
	matrix<double> L; // forward rates
	matrix_resize(L, N + 1, N + 1);
	matrix<double> D; // discount factors
	matrix_resize(D, N + 2, N + 2);

	vector<double> dW(N + 1); // discount factors
	vector<double> FV(N + 2); // future value payment
	vector<double> FVprime(N + 2); // numeraire-rebased FV payment
	vector<double> V(M); // simulation payoff

	// Composing the SampleBoxMuller class:

	SampleBoxMuller normal;
	
	double df_prod = 1.0;
	double drift_sum = 0.0;

	double sumPV = 0.0;
	double PV = 0.0;

	// STEP 2: INITIALISE SPOT RATES

	L[0][0] = 0.05;
	L[1][0] = 0.05;
	L[2][0] = 0.05;
	L[3][0] = 0.05;

	// start main MC loop

	for (int nsim = 0; nsim < M; ++nsim)
	{

		// STEP 3: BROWNIAN MOTION INCREMENTS

		dW[1] = sqrt(dT)*normal();
		dW[2] = sqrt(dT)*normal();
		dW[3] = sqrt(dT)*normal();

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
				L[i][n + 1] = L[i][n] * exp((-drift_sum*sigma - 0.5*sigma*sigma)*dT + sigma*dW[n + 1]); // cout <<“L: i= “ << i <<“, n+1 = “ << n+1 “ << L[i][n+1] << “\n”;
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
				// cout <<“D: i = “ << i <<“, n = “ << n <<“, D[i][n] = “ << D[i][n] << “\n”;
			}
		}

		// STEP 6: COMPUTE EFFECTIVE FV PAYMENTS

		FV[1] = notional*alpha*(L[0][0] - K);
		FV[2] = notional*alpha*(L[1][1] - K);
		FV[3] = notional*alpha*(L[2][2] - K);
		FV[4] = notional*alpha*(L[3][3] - K);

		// STEP 7: COMPUTE NUMERAIRE-REBASED PAYMENT

		FVprime[1] = FV[1] * D[1][0] / D[4][0];
		FVprime[2] = FV[2] * D[2][1] / D[4][1];
		FVprime[3] = FV[3] * D[3][2] / D[4][2];
		FVprime[4] = FV[4] * D[4][3] / D[4][3];

		// STEP 8: COMPUTE IRS NPV

		V[nsim] = FVprime[1] * D[1][0] + FVprime[2] * D[2][0] + FVprime[3] * D[3][0] + FVprime[4] * D[4][0];
	}
	// end main MC loop

	// STEP 9: COMPUTE DISCOUNTED EXPECTED PAYOFF

	sumPV = 0.0;
	for (int nsim = 0; nsim < M; nsim++)
	{
		sumPV += V[nsim];
	}

	PV = sumPV / M;

	IR_results results(V, PV);

	return results;
}
