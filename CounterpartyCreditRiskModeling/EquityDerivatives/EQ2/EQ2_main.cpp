// EQ2_main.cpp

// requires EQ2.cpp and random.cpp

#include "EQ2.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "\n *** START EQ2: Monte Carlo equity basket *** \n";

	// STEP 1: INPUT PARAMETERS

	auto T = 1.0; // maturity
	auto r = 0.05; // interest rate
	auto S10 = 120.0; // spot equity 1
	auto S20 = 100.0; // spot equity 2
	auto sigma1 = 0.10; // volatility
	auto sigma2 = 0.15; // volatility
	auto rho = 0.5; // correlation
	auto N = 300; // nuber of steps
	auto M = 10000; // nuber of simulations

	// Construct a EQ2 object from the input parameters:

	EQ2 eq2(T, r, S10, S20, sigma1, sigma2, rho, N, M);

	// Obtain the value of premium from member function "get_premium()": 

	auto premium = eq2.get_premium();

	// STEP 6: OUTPUT RESULTS

	cout << "\n premium =  " << premium << endl;
	cout << "\n *** END EQ2: Monte Carlo equity basket *** \n";

	return 0;
}
