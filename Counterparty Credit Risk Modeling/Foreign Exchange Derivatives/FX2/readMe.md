# (Advanced Demonstration) - FX Barrier Option

In this slightly more advanced example, we will consider the pricing of an exotic option: an up-and-out barrier with a call payoff.

## Step 1: The Derivative Contract

*A "FOREX Up-and-Out Barrier Call" option on the EUR/USD exchange rate* involves two counterparties, 
A (the EUR party) and B (the USD party). The option's underlying asset is the EUR/USD exchange rate. 
Initially, at time $t=0$, A pays B a *premium*. At maturity $(T=1 year)$, 
A gains the option to purchase a specified amount $N$ of USD from B at the strike rate $K$. 
The payoff at maturity, denoted as $H$, is determined by the option's conditions :

$$H (X_T) = max(X_T - K , 0)$$

## Step 2: The Mathematical Model

As mentioned, the *underlying* for this contract is a forex rate; it can be chracterized using the Garman-Kohlhagen model :

$$dX = (r_d - r_f)Xdt + \sigma XdW $$

## Step 3: The Numerical Method

To attain the option premium at $t=0$, we must compute the value of the option surface using the *explicit Finite Difference method* : 

$$ \pi = V(S_0, 0) $$


## Step 4: The Algorithm

- **STEP 1:** INPUT PARAMETERS
- **STEP 2:** SETUP MESH
- **STEP 3:** SETUP INITIAL CONDITION
- **STEP 4:** SETUP BOUNDARY CONDITIONS
- **STEP 5:** COMPUTE FORWARD DIFFERENCES
```plaintext
for j=0 to M-2
  for i=1 to N-2
    *compute FDM stencil for each internal node
  end I
end j
```
- **STEP 6:** TRANSFORM SOLUTION FROM X TO S COORDINATES
