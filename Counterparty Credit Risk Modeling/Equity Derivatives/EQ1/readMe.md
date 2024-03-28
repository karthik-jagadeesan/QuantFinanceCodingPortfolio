# (Basic Demonstration) - European Call
In this initial instance, we explore the valuation of a vanilla European Call option. 
Although this example may seem straightforward, it holds significant importance as it lays the foundation for solving more complex option pricing challenges using Monte Carlo simulation.


## Step 1: The Derivative Contract
European Call option for Barclays Bank PLC stock involving counterparties A and B. The underlying asset is Barclays stock. At time $t=0$, party A pays party B a *premium*. At maturity $(T=1 year)$, party A holds the right (but not the obligation) to purchase the underlying asset from party B at the strike price $K$. The payoff at maturity, denoted as $H$, is described as follows:

$$H(S_T) = max(S_T - K, 0) $$

## Step 2: The Mathematical Model
The *underlying* for this contract is a stock; it can be characterized using *Geometric Brownian Motion* :
$$dS = rSdt + \sigma SdW $$

## Step 3: The Numerical Methodology
We can use *Monte Carlo Simulation* as a means to compute the value of the discounted expected payoff. This is will end up being our premium value for the option: 

$$\pi = exp(-rT) \times E^Q[H(S_T)] $$ 

## Step 4: The Algorithm

- **STEP 1:** INPUT PARAMETERS
- **STEP 2:** SIMULATIONS LOOP
```
for i=1:M
  STEP 3: TIME INTEGRATION LOOP 
  for 1=1:N
    *Compute GBM formula at each timestep
  end
  STEP 4: COMPUTE PAYOFF
end
```
- **STEP 5:** COMPUTE DISCOUNTED EXPECTED PAYOFF
- **STEP 6:** OUTPUT PREMIUM VALUE
