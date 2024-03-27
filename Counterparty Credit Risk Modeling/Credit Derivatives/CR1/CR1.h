// CR1.h

#ifndef CR1_H
#define CR1_H

class CR1_results {

public:

	CR1_results()
		: equity_payoff(0), percentage_defaults(0) {}

	double equity_payoff;
	double percentage_defaults;
};

class CR1 {

public:

	// Defualt constructor:

	CR1() :T(4), D(70), V0(100), sigma(0.20),
		r(0.05), N(500), M(1000){}

	// Constructor from input arguments:

	CR1(double _T, double _D, double _V0,
		double _sigma, double _r, int _N, int _M) 
		:T(_T), D(_D), V0(_V0), sigma(_sigma),
		r(_r), N(_N), M(_M){}

	// A function to extract the payoff 
	// and percentage defaults:

	CR1_results get_payoff_and_defaults() const
	{
		return find_payoff_and_defaults();
	}

private:

	double T; // maturity
	double D; // debt of the firm
	double V0; // initial assets of the firm
	double sigma; // volatility of the assets of the firm
	double r; // risk free interest rate
	int N; // number of steps
	int M; // number of simulations

	// A function to estimate the payoff 
	//					and percentage defaults:

	CR1_results find_payoff_and_defaults() const;

};

#endif