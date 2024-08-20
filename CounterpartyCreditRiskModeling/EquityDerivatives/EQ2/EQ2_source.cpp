// EQ2_source.cpp

#include <algorithm>
#include <vector>
#include <cmath>
#include "EQ2.h"
#include "random.h"

using namespace std;

double EQ2::find_premium() const
{
	vector <double> S1(N + 1);
	vector <double> S2(N + 1);
	auto sumpayoff = 0.0;
	auto premium = 0.0;
	auto dt = T / N;

	// Composing the SampleBoxMuller class:

	SampleBoxMuller normal;

	// STEP 2: MAIN SIMULATION LOOP

	for (int j = 0; j < M; j++)
	{
		S1[0] = S10;
		S2[0] = S20;

		// STEP 3: TIME INTEGRATION LOOP

		for (int i = 0; i < N; i++)
		{
			static double epsilon1, epsilon2;
			epsilon1 = normal();
			epsilon2 = normal();
			S1[i + 1] = S1[i] * (1 + r*dt + sigma1*sqrt(dt)*epsilon1);
			S2[i + 1] = S2[i] * (1 + r*dt + sigma2*sqrt(dt)
							*(epsilon1*rho + sqrt(1 - rho*rho)*epsilon2));
		}

		// STEP 4: TIME INTEGRATION LOOP

		sumpayoff += max(S1[N], S2[N]);
	}

	// STEP 5: COMPUTE DISCOUNTED EXPECTED PAYOFF

	premium = exp(-r*T)*(sumpayoff / M);

	return premium;
}