// FX.h

#ifndef FX_H
#define FX_H

#include "matrix.h"
#include <iostream>
#include <iomanip>

using vec = std::vector<double>;

//-----------------------------------------
// structure of output result data:

struct result_data{

	result_data(){}

	result_data(double _alpha, double _dtau,
		double _k, vec _x, vec _S, vec _t, vec _tau,
		matrix<double> _u, matrix<double> _v)
		: alpha(_alpha), dtau(_dtau), k(_k),
		x(_x), S(_S), t(_t), tau(_tau), u(_u), v(_v) {}

	double alpha;
	double dtau;
	double k;
	vec x;
	vec S;
	vec t;
	vec tau;
	matrix<double> u;
	matrix<double> v;

	// to print out the structure

	friend std::ostream& operator << (std::ostream& os, const result_data& rs);
};

//-------------------------------
//
// Main class for FX

class FX {

public:

	// Default constructor:

	FX() :T(0.5), K(75), S0(75), sigma(0.30),
		r(0.05), dt(0.1), dx(0.5), N(5), M(6){}

	// Constructor from input arguments:

	FX(double _T, double _K, double _S0, double _sigma,
		double _r, double _dt, double _dx, int _N, int _M)
		:T(_T), K(_K), S0(_S0), sigma(_sigma),
		r(_r), dt(_dt), dx(_dx), N(_N), M(_M) {}

	// A function to extract the data and premium value:

	result_data get_data_and_premium() const
	{
		return evaluate_data_and_premium();
	}

private:

	// Data members:

	// STEP 1: INPUT PARAMETERS

	double T; // maturity
	double K; // strike
	double S0; // spot
	double sigma; // volatility
	double r; // interest rate
	int N; // number of space steps
	int M; // number of time steps
	double dt; // time step
	double dx; // space step

	// A function to evaluate data_and_premium:

	result_data evaluate_data_and_premium() const;
};

//----------------------------

#endif
