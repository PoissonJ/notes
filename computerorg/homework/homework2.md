Jonathan Poisson |  Homework 2

# 1

## a

25% + 10% = 35%

## b

20% + 25% + 25% + 1-% = 80%

#2

## 2.1

| RAW on R2 from I2 to I3
| RAW on R1 from I1 to I2 and I3
| WAR on R1 from I2 to I3
| WAR on R2 from I1 to I2
| WAW on R1 from I1 to I3

## 2.2

| or R1, R2, R3
| NOP
| NOP  Delay I2 in order to avoid the RAW on R1 from I1
| or R2, R1, R4
| NOP
| NOP   Delay I3 in order to avoid RAW on R2 from I2
| or R1, R1, R2

## 2.3

There will be no NOP's in this set of instructions when using full forwarding.
The RAW hazard on R1 from I1 is avoided through forwarding and the RAW hazard
from I2 to R2 is avoided through forwarding.

## 2.4

### No forwarding

(7 + 4) * 180ps = 1980ps

### With forwarding

7 * 240ps = 1680ps

### Speedup due to forwarding

1980/1680 = 1.18

# 3

## 3.1

---------------  -- --- -- --- --- -- --- ---
LW  R1,0(R1)     WB
LW  R1,0(R1)     EX MEM WB
BEQ R1, R0, Loop ID **  EX MEM WB
LW  R1,0(R1)     IF **  ID EX  MEM WB
AND R1, R1, R2          IF ID  **  EX MEM WB
LW  R1,0(R1)               IF  **  ID EX  MEM
LW  R1,0(R1)                       IF ID  **
BEQ R1, R0, Loop                      IF  **
---------------  -- --- -- --- --- -- --- ---

## 3.2

There are 8 cycles per loop iteration and only 2 cycles in which all of the
stages are doing useful work. This means that there is a total of **0%** of cycles
in which *all* the stages are doing useful work.

# 4

## 4.1

Cpi:
  : 1 + 0.35 * 2 + 0.15 * 1 = **1.85**

Stall Cycles:
  : 0.85/1.85 = **46%**

## 4.2

CPI:
  : 1 + 0.20 = **1.20**

Stall Cycles:
  : 0.20/1.20 = **17%**

## 4.3

EX/MEM:
  : 0.2 + 0.05 + 0.1 + 0.1 = **0.45**

MEM/WB:
  : 0.05 + 0.2 + 0.1 = **0.35**

There will be fewer stall cycles with **MEM/WB**

## 4.4

Without Forwarding:
  : 1.85 * 150ps = **277.5ps**

With Forwarding:
  : 1.20 * 150ps = **180ps**

There is a speedup of **1.54**

#5

## a

Always Taken:
  : 3/5 = **60%**

Always Not Taken:
  : 2/5 = **40%**

## b

Outcomes:
  : T, NT, T, T

Value of the Predictor:
  : 0 (Incorrect), 1 (Correct), 0 (Incorrect), 1 (Incorrect)

This leads to a total accuracy of **25%**

