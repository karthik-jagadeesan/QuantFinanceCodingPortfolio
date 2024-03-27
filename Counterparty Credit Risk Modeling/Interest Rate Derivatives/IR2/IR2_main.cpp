// IR2_main.cpp
// requires random.cpp IR2_source.cpp

#include "IR.h"
#include <iostream>
using namespace std;

int main()
{
	std::cout << "\n *** START IR2: CAP Monte Carlo Libor Market Model 1F * ** \n\n";

	// STEP 1: INPUT PARAMETERS
	double K = 0.05; // strike caplet
	double alpha = 0.5; // daycount factor
	double sigma = 0.15; // fwd rates volatility
	double dT = 0.5;
	int N = 4; // number forward rates
	int M = 1000; // number of simulations

	// Construct a IR object from the input parameters:

	IR ir2(K, alpha, sigma, dT,  N, M);

	// Obtain the value of premium from member function "get_premium()":

	auto results = ir2.get_simulation_data();

	// STEP 10: OUTPUT RESULTS

	auto sz = results.datapoints.size();

	for (decltype(sz) nsim = 0; nsim < sz; ++nsim)
	{
		cout << "Vcap[" << nsim << "] = " << results.datapoints[nsim] << endl;
	}

	cout << "\n *** IRS cap = " << results.Value << "\n";

	cout << "\n *** END IR2: CAP Monte Carlo Libor Market Model 1F * ** \n";

	return 0;
}
