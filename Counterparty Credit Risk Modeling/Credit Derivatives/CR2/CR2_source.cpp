// CR2_source.cpp

#include "CR2.H"
#include <vector>
#include <cmath>

using namespace std;

CR2_results CR2::find_pv_premium_and_default_legs_and_cds_spread() const
{
	auto pv_premium_leg = 0.0; // sum premium leg
	auto pv_default_leg = 0.0; // sum default leg
	auto t = 0.0; // current time
	auto cds_spread = 0.0;

	auto array_size = static_cast<int>(N*T + 1);
	vector <double> DF(array_size);
	vector <double> P(array_size);

	P[0] = 1.0;

	auto dt = T / N;

	// STEP 2: LOOP FOR ALL PAYMENTS

	for (int j = 1; j < array_size; j++)
	{
		t = j*dt;
		DF[j] = exp(-r*t);
		P[j] = exp(-h*t);

		// STEP 3: COMPUTE PREMIUM PAYMENTS

		pv_premium_leg = pv_premium_leg + DF[j] * notional*dt*P[j];

		// STEP 4: COMPUTE DEFAULT PAYMENTS

		pv_default_leg = pv_default_leg + DF[j] * (1.0 - rr)*notional*(P[j - 1] - P[j]);
	}

	// STEP 5: COMPUTE CDS SPREAD

	cds_spread = pv_default_leg / pv_premium_leg;

	// Composing the CR2_results class:

	CR2_results results;

	results.pv_premium_leg = pv_premium_leg;

	results.pv_default_leg = pv_default_leg;

	results.cds_spread_in_bps = cds_spread * 10000;

	return results;
}
