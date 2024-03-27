// EQ2.h

#ifndef EQ2_H
#define EQ2_H

class EQ2 {

public:

	// Defualt constructor:

	EQ2() :T(1), r(0.05), S10(120), S20(100),
		sigma1(0.10), sigma2(0.15), rho(0.5), N(300), M(1000){}

	// Constructor from input arguments:

	EQ2(double _T, double _r, double _S10, double _S20,
		double _sigma1, double _sigma2, double _rho, int _N, int _M)
		:T(_T), r(_r), S10(_S10), S20(_S20),
		sigma1(_sigma1), sigma2(_sigma2), rho(_rho), N(_N), M(_M){}

	// A function to extract the premium value:

	double get_premium() const
	{
		return find_premium();
	}

private:

	// Data members:

	double T; // maturity
	double r; // interest rate
	double S10; // spot equity 1
	double S20; // spot equity 2
	double sigma1; // volatility
	double sigma2; // volatility
	double rho; // correlation
	int N; // number of steps
	int M; // number of simulations

	// A function to estimate premium:

	double find_premium() const;
};

#endif