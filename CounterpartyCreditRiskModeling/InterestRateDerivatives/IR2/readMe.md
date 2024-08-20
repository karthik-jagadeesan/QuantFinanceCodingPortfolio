# (Advanced Demonstration) - Interest Rate Swap with Cap
In this example, we are tasked with pricing an IRS with a cap. 

## Step 1: The Derivative Contract
The contract is an *IRS with CAP* whose duration is 2.5 years. The payments are due every 6 months; the notional is 1 EUR with 
a strike of 5%. The floating rate is EURIBOR6M. This contract has a flat term structure at 5% and forward rates volatility is 15% : 

$$PV = \sum_{i=0}^{x} Notional \times DF_i \times \alpha \times  max(L_i - K, 0)$$

## Step 2: The Mathematical Model
Under the purview of the *Libor Market Model* the floating rates can be characterized using *Geometric Brownian Motion* : 

$$dL_i = \mu L_i dt + \sigma L_i dW $$
## Step 3: The Numerical Methodology 
Here we enforce *Monte Carlo Simulation* as a way to compute the values of the forward rates using the *Pelsser Tableau*.

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
  STEP 8: COMPUTE CAP PAYOFF
end
```
- **STEP 9:** COMPUTE DISCOUNTED EXPECTED PAYOFF
- **STEP 10:** OUTPUT RESULTS
