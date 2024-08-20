// CR2_main.cpp

// It requires CR2_source.cpp
#include "CR2.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "\n *** START CR2: Credit Default Swap *** \n";

	// STEP 1: INPUT PARAMETERS

	auto T = 1.0; // maturity
	auto N = 4; // number of payments per year
	auto notional = 100.0; // notional
	auto r = 0.05; // risk free interest rate
	auto h = 0.01; // hazard rate
	auto rr = 0.50; // recovery rate

	// Construct a CR2 object from the input parameters:

	CR2 cr2(T, N, notional, r, h, rr);

	// Obtain the value of premium from member function "get_premium()":

	auto cr2_results = cr2.get_pv_premium_and_default_legs_and_cds_spread();

	// STEP 6: OUTPUT RESULTS

	cout << "\n PV premium leg =  "
			<< cr2_results.pv_premium_leg << "\n";

	cout << "\n PV default leg =  "
			<< cr2_results.pv_default_leg << " \n";

	cout << "\n cds_spread =  "
			<< cr2_results.cds_spread_in_bps << "  bps \n";

	cout << "\n *** END CR2: Credit Default Swap *** \n";

	return 0;
}
