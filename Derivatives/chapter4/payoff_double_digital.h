#ifndef __PAY_OFF_DOUBLE_DIGITAL_H
#define __PAY_OFF_DOUBLE_DIGITAL_H

#include "payoff.h"

class PayOffDoubleDigital : public PayOff {
 private:
  double U;  // Upper strike price
  double D;  // Lower strike price

 public:
  // Two strike parameters for constructor
  PayOffDoubleDigital(const double _U, const double _D);

  // Destructor
  virtual ~PayOffDoubleDigital();

  // Pay-off is 1 if spot within strike barriers, 0 otherwise
  virtual double operator() (const double S) const;
};

#endif
