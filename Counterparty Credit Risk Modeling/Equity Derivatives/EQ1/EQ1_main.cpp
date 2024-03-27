// EQ1_main.cpp

// It requires EQ1_source.cpp and random.cpp

#include "EQ1.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "\n *** START EQ1: Monte Carlo European Call *** \n";

	// STEP 1: INPUT PARAMETERS

	auto T = 1.0; // maturity
	auto K = 100.0; // strike
	auto S0 = 100.0; // spot
	auto sigma = 0.10; // volatility
	auto r = 0.05; // interest rate
	auto N = 500; // number of steps
	auto M = 10000; // number of simulations

	// Construct a EQ1 object from the input parameters:

	EQ1 eq1(T, K, S0, sigma, r, N, M);

	// Obtain the value of premium from member function "get_premium()":

	auto premium = eq1.get_premium();

	// STEP 6: OUTPUT RESULTS

	cout << "\n premium =  " << premium << endl;
	cout << "\n *** END EQ1: Monte Carlo single asset *** \n";
	// system("notepad");
}
