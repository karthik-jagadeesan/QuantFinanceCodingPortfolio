//  random.h

#ifndef RANDOM_H
#define RANDOM_H

class SampleBoxMuller {
	
public:

	double operator()();

private:

	double result;
	double x;
	double y;
	double xysquare;
};

#endif