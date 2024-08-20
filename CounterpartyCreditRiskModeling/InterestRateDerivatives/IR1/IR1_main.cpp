// IR1_main.cpp
// requires random.cpp IR1_source.cpp

#include "IR.h"
#include <iostream>
using namespace std;

int main()
{

	cout << "\n *** START IR1: IRS Monte Carlo Libor Market Model 1F * ** \n\n";

	// Plain Vanilla IRS, pays fixed, receives floating
	// freq payments every 3M, maturity 1 year

	// STEP 1: INPUT PARAMETERS

	double notional = 1000000; // notional
	double K = 0.04; // fixed rate IRS
	double alpha = 0.25; // daycount factor
	double sigma = 0.15; // fwd rates volatility
	double dT = 0.25;
	int N = 3; // number forward rates
	int M = 1000; // number of simulations

	// Construct a IR object from the input parameters:

	IR ir1(notional, K, alpha, sigma, dT, N, M);

	// Obtain the value of premium from member function "get_premium()":

	auto results = ir1.get_simulation_data();

	// STEP 10: OUTPUT RESULTS

	auto sz = results.datapoints.size();
	for (decltype(sz) nsim = 0; nsim < sz; ++nsim)
	{
		cout << "simIRS[" << nsim << "] = " << results.datapoints[nsim] << endl;
    }

	cout << "\n *** IRS PV = " << results.Value << endl;
	cout << "\n *** END IR1: IRS Monte Carlo Libor Market Model 1F *** \n";

	return 0;
}
