# (Advanced Demonstration) - Equity Basket
In this example, we deal with a more sophisticated demonstration, we'll showcase how to execute the valuation of an equity basket option. This option's payoff is determined by selecting the highest value between two asset prices at the maturity date.

## Step 1: The Derivative Contract
*Equity Basket option based on the maximum value of two assets*, involving counterparties A and B. The underlying assets are Barclays stock and Rolls Royce stock. At time $t=0$, party A pays party B a *premium*. At maturity $(T=1 year)$, party A will receive from party B the payoff $H$, as described below :

$$H(S1_T, S2_T) = max(S1_T, S2_T) $$

## Step 2: The Mathematical Model
The *underlyings* for this contract are stocks; it can be characterized using *Geometric Brownian Motion process* :
$$dS1 = rS1dt + \sigma_1 S1dW_1 $$

$$dS2 = rS2dt + \sigma_2 S2dW_2 $$

## Step 3: The Numerical Methodology
We enforce *Monte Carlo Simulation* to compute the value of the discounted expected payoff of the contract :

$$\pi = exp(-rT) * E^Q[H(S1_T, S2_T)] $$

## Step 4: The Algorithm
- **STEP 1:** INPUT PARAMETERS

- **STEP 2:** SIMULATIONS LOOP
```plaintext
for i=1:M
  STEP 3: TIME INTEGRATION LOOP
  for j=1:N
    *Compute GBM for asset 1 at each timestep
    *Compute GBM for asset 2 at each timestep
  end
  STEP 4: COMPUTE BASKET PAYOFF
end
```
- **STEP 5:** COMPUTE DISCOUNTED EXPECTED BASKET PAYOFF
- **STEP 6:** OUTPUT BASKET PREMIUM VALUE
