// IR.h

#ifndef IR_H
#define IR_H

#include <vector>

using namespace std;

struct IR_results {

	IR_results(){}

	IR_results(vector<double> _datapoints, double _Value)
		: datapoints(_datapoints), Value(_Value) {}

	vector<double> datapoints;
	double Value;

};

class IR {

public:

	// Defualt constructor:

	IR() : notional(0), K(0.05), alpha(0.5), sigma(0.15), dT(0.5), N(4), M(10000) {}

	// Constructor from input arguments:

	// FOR IR1:

	IR(double _notional, double _K, double _alpha, double _sigma, double _dT, int _N, int _M)
		: notional(_notional), K(_K), alpha(_alpha), sigma(_sigma), dT(_dT), N(_N), M(_M) {}

	// For IR2:

	IR(double _K, double _alpha, double _sigma, double _dT, int _N, int _M)
		: K(_K), alpha(_alpha), sigma(_sigma), dT(_dT), N(_N), M(_M) {}
	
	// A function to extract the data and premium value:

	IR_results get_simulation_data() const
	{
		return run_LIBOR_simulations();
	}

private:

	// Data members:

	double notional; // notional
	double K; // strike caplet
	double alpha; // daycount factor
	double sigma; // fwd rates volatility
	double dT;
	int N; // number forward rates
	int M; // number of simulations

	// A function to evaluate data_and_premium:

	IR_results run_LIBOR_simulations() const;
};

#endif