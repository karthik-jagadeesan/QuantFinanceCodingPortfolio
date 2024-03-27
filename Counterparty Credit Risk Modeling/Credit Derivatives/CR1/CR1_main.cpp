// CR1_main.cpp

// It requires CR1_source.cpp and random.cpp

#include "CR1.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "\n *** START CR1: Monte Carlo Merton Model *** \n";

	// STEP 1: INPUT PARAMETERS

	auto T = 4.0; // maturity
	auto D = 70.0; // debt of the firm
	auto V0 = 100.0; // initial assets of the firm
	auto sigma = 0.20; // volatility of the assets of the firm
	auto r = 0.05; // risk free interest rate
	auto N = 500; // number of steps
	auto M = 10000; // number of simulations

	// Construct a CR1 object from the input parameters:

	CR1 cr1(T, D, V0, sigma, r, N, M);

	// Obtain the value of premium from member function "get_premium()":

	auto cr1_results = cr1.get_payoff_and_defaults();

	// STEP 7: OUTPUT RESULTS

	cout << "\n equity payoff (E(0)) =  " << cr1_results.equity_payoff << "\n";
	cout << "\n percentage defaults =  " << cr1_results.percentage_defaults << " percent \n";
	cout << "\n *** END CR1: Monte Carlo Merton Model *** \n";

	return 0;
}
