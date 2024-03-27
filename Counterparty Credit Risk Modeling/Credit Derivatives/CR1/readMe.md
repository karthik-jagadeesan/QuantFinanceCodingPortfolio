# (Basic Demonstration) - Bankruptcy
Here we examine and model the default of a firm using the Merton model. Under this idea, the dynamics of the firm obeys the following 
properties for simplicity : 

**- Firm's assets $(V)$ is composed only of equity $(E)$ and debt $(D)$**

**- Under timeframe to maturity $(T)$, the defualt event for the firm occurs when the assets under the firm at maturity 
$V(T)$ are lower than the value of the debt $(D)$ that the firm is obligated to pay at that time**

Furthermore, we can examine the probability of the firm's default by enforcing the Monte Carlo Simulation. By doing so, we 
generate a collection of possible trajectories that detail the firm's evolution through time. With the collection of scenarios,
we can count those that satisy the firm defualt condition; and from there we can estimate the likelihood of 
bankruptcy of the firm.

## Step 1 : The Derivative Contract

The firm's assets $(V)$ are the sum of the firm's equity $(E)$ and it's debt $(D)$. Default condition is met when $V(T) < D(T)$, observed
at maturity. Under Merton's model, he believed that the firm's equity with said characteristics is essentially a European Call
Option with the following payoff function : 

$$H(V_T) = max(V_T - D, 0)$$

## Step 2 : The Mathematical Model
Under the Merton model, the firm characteristics can be characterized using *Geometric Brownian Motion* : 

$$ dV = rVdt + \sigma VdW $$


## Step 3 : The Numerical Methodology
Here we can employ *Monte Carlo Simulation* to compute the value of the equity under the firm as the discounted expected payoff :

$$ \pi = exp(-rT) \times E^{Q}[H(V_T)] $$


## Step 4 : The Algorithm

- **STEP 1:** INPUT PARAMETERS
- **STEP 2:** MAIN SIMULATION LOOP
```
for i=1:M
  STEP 3: TIME INTEGRATION LOOP
  for i=1:N
    *Compute GBM formula at each timestep for firm value V
    end
  STEP 4: COMPUTE PAYOFF
  STEP 5: COMPUTE NUMBER DEFAULTS
end
```
- **STEP 6:** COMPUTE DISCOUNTED EXPECTED PAYOFF
- **STEP 7:** OUTPUT EQUITY VALUE AND DEFAULT PROBABILITY
