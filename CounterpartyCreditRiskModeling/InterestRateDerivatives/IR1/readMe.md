# (Basic Demonstration) - Plain vanilla Interest Rate Swap


## Step 1: The Derivative Contract 
The contract here will be a plain vanilla *Interest Rate Swap*. It has a duration of 1 year with payments due every 3 months. The notional 
amount is 1 million EUR. The Fixed rate is 4% and the floating rate is EURIBOR3M. It has a flat term structure at 5%, and finally, its 
volatility is 15% : 

$$ PV = \sum_{i=0}^{N} \text{Notional} \times DF_i \times a \times (L_i - K) $$


## Step 2: The Mathematical Model 
Under the purview of the *Libor Market Model* the floating rates can be characterized using *Geometric Brownian Motion* :

$$ dL_i = \mu L_idt + \sigma L_i dW $$

## Step 3: The Numerical Methodology
Here we enforce *Monte Carlo Simulation* as a means for computing the value pertaining to the forwards rates.


## Step 4: The Algorithm

- **STEP 1:** INPUT PARAMETERS
- **STEP 2:** INITIALIZE SPOT RATES
- **STEP 3:** BROWNIAN MOTION INCREMENTS
```
for i=1:M (SIMULATIONS)
  STEP 4: COMPUTE FORWARD RATES
  STEP 5: COMPUTE DISCOUNT FACTORS
  STEP 6: COMPUTE EFFECTIVE FV RATES
  STEP 7: COMPUTE NUMERAIRE REBASED PAYMENT
  STEP 8: COMPUTE IRS NPV
end
```
- **STEP 9:** COMPUTE DISCOUNTED EXPECTED PAYOFF
- **STEP 10:** OUTPUT RESULTS
