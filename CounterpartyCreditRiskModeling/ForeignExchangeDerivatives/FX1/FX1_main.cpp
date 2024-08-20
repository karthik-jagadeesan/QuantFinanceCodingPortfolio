// FX_EQ1_main.cpp

// requires FX_source.cpp, FX_print.cpp

#include "FX.h"


using namespace std;

int main()
{
	cout	<< "\n *** START FX1: Finite Difference European Call *** \n\n";

	// STEP 1: INPUT PARAMETERS

	auto T = 0.5; // maturity
	auto K = 75.0; // strike
	auto S0 = 75.0; // spot
	auto sigma = 0.30; // volatility
	auto r = 0.05; // interest rate

	auto dx = 0.5; // space step
	auto dt = 0.1; // time step
	auto N = 5; // number of space steps
	auto M = 6; // number of time steps

	// Construct a FX_EQ1 object from the input parameters:

	FX fx_eq1(T, K, S0, sigma, r, dt, dx, N, M);

	// Ask the object to evaluate the FX data for European Call:

	auto result = fx_eq1.get_data_and_premium();

	// STEP 7: OUTPUT RESULTS

	cout << result;

	cout << "\n *** END FX1: Finite Difference European Call *** \n";

	return 0;
}
