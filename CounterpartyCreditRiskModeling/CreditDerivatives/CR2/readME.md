# (Advanced Demonstration) - Credit Defualt Swap
Here, we are tasked with pricing a CDS contract. 

## Step 1: The Derivative Contract
In a *Credit Defualt Swap*, counterparty A will pay to counterparty B regular *premium* payments in exchange for credit insurance/protection,
which is, the default of party C with notional amount $N$. If C defaults, B will pay A a one-off compensation payment whose amount is 
$N(1-R)$. The price of said CDS willl be the premium that we will compute. 


## Step 2: The Mathematical Model
Under the *Intensity Framework*, the survival probability $P(T)$ of the underlying C is as follows : 

$$ P(t) = exp(-\lambda t) $$


## Step 3: The Numerical Methodology
The pricing calculation of the CDS is that of a deterministic nature. The premium is essentially the equating of present value to the present value
of the defualt legs.

## Step 4: The Algorithm
- **STEP 1:** INPUT PARAMETERS
- **STEP 2:** LOOP FOR ALL PAYMENTS
```
for i=1:M
  STEP 3: Compute Premium Leg (PL) payments
  STEP 4: Compute Default Leg (DL) payments
end
```
- **STEP 5:** COMPUTE CDS SPREAD
- **STEP 6:** OUTPUT RESULTS
