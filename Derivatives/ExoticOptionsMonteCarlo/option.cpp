#ifndef __OPTION_CPP
#define __OPTION_CPP

#include "option.h"

VanillaOption::VanillaOption() {}

VanillaOption::VanillaOption(double _K, double _r, double _T, 
                             double _sigma, PayOff* _pay_off) : 
  K(_K), r(_r), T(_T), sigma(_sigma), pay_off(pay_off) {}

#endif
