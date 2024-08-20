// EQ1.h

#ifndef EQ1_H
#define EQ1_H

class EQ1 {

public:

	// Defualt constructor:

	EQ1() :T(1), K(100), S0(100), sigma(0.10),
		r(0.05), N(500), M(1000){}

	// Constructor from input arguments:

	EQ1(double _T, double _K, double _S0,
		double _sigma, double _r, int _N, int _M)
		:T(_T), K(_K), S0(_S0), sigma(_sigma),
		r(_r), N(_N), M(_M){}

	// A function to extract the premium value:

	double get_premium() const
	{
		return find_premium();
	}

private:

	// Data members:

	double T; // maturity
	double K; // strike
	double S0; // spot
	double sigma; // volatility
	double r; // interest rate
	int N; // number of steps
	int M; // number of simulations

	// A function to estimate premium:

	double find_premium() const;

};

#endif