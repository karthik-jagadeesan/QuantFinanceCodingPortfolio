// EQ1_source.cpp
// It requires random.cpp

#include "random.h"

#include <algorithm>
#include <vector>
#include "EQ1.H"

double EQ1::find_premium() const
{
	auto sumpayoff = 0.0;
	auto premium = 0.0;
	auto dt = T / N;
	std::vector <double> S(N + 1);

	// Composing the SampleBoxMuller class:

	SampleBoxMuller normal;

	// STEP 2: MAIN SIMULATION LOOP

	for (int j = 0; j < M; j++)
	{
		S[0] = S0;

		// STEP 3: TIME INTEGRATION LOOP

		for (int i = 0; i < N; i++)
		{
			double epsilon = normal();
			S[i + 1] = S[i] * (1 + r*dt + sigma*sqrt(dt)*epsilon);
		}

		// STEP 4: COMPUTE PAYOFF

		static auto diff = 0.0;
		diff = S[N] - K;
		sumpayoff += std::max(diff, 0.0);

	}

	// STEP 5: COMPUTE DISCOUNTED EXPECTED PAYOFF

	premium = exp(-r*T)*(sumpayoff / M);

	return premium;
}
