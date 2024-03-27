// CR1_source.cpp
// It requires random.cpp

#include "random.h"

#include <algorithm>
#include <vector>
#include "CR1.h"

using namespace std;

CR1_results CR1::find_payoff_and_defaults() const
{
	vector <double> V(N + 1);
	auto sumpayoff = 0.0;
	auto dt = T / N;
	auto default_count = 0.0;

	// Composing the SampleBoxMuller class:

	SampleBoxMuller normal;

	// STEP 2: MAIN SIMULATION LOOP

	for (auto j = 0; j < M; j++)
	{
		V[0] = V0;

		// STEP 3: TIME INTEGRATION LOOP

		for (auto i = 0; i < N; i++)
		{
			double epsilon = normal();
			V[i + 1] = V[i] * (1 + r*dt + sigma*sqrt(dt)*epsilon);
		}

		// STEP 4: COMPUTE PAYOFF

		sumpayoff += max(V[N] - D, 0.0);

		// STEP 5: COMPUTE NUMBER DEFAULTS

		if (V[N]>D)
		{
			++default_count;
		}

	}

	// STEP 6: COMPUTE DISCOUNTED EXPECTED PAYOFF
	// EQUITY VALUE (E) AT TIME=0

	// Composing the CR1_results class:

	CR1_results results;

	results.equity_payoff = exp(-r*T)*(sumpayoff / M);

	results.percentage_defaults = default_count / M * 100;

	return results;
}
