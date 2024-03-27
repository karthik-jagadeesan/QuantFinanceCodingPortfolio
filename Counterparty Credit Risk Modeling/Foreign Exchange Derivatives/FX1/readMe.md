# (Basic Demonstration) - Basic European FX Call
In this example, we demonstrate the pricing of a plain vanilla European Call 
option on foreign exchange. Our aim here is to calculate the premium of this 
financial derivative.

## Step 1: The Derivative Contract
  
A *Forex European Call option is based on the EUR/USD exchange rate*, involving counterparties A (representing the EUR party) and B (representing the USD party). 
At the outset $(t=0)$, A pays B a *premium*. Upon maturity $(T=1year)$, 
A gains the option to purchase a specified amount $N$ of USD from B at the strike rate $K$. 
The payoff at maturity, denoted by $H$, is determined by the arrangement :

$$H(X_T) = \max(X_T - K, 0)$$


## Step 2: The Mathematical Model

As the *underlying* is a forex rate, it can be characterized using the *Garman-Kohlhagen model* :

$$dX = (v\_g - r\_f)X dt + \sigma X dW$$

## Step 3: The Numerical Method

In an attempt to attain the value of the premium for the given option at time $t=0$, we must compute the value of the option surface via *explicit Finite Difference method* :

$$\pi = V(S\_0, 0)$$


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
        end i
    end j
    ```
- **STEP 6:** TRANSFORM SOLUTION FROM X TO S COORDINATES
