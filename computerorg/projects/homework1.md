# Problem 2

## A

1 Processor

 * `((2.56 * 10^9) + (1.28 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 9.60 seconds
 * Relative Speed: `9.60 / 9.60` = `1`

2 Processor

 * `((1.86 * 10^9) + (0.91 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 7.02 seconds
 * Relative Speed: `9.60 / 7.02` = `1.37`

4 Processor

 * `((0.91 * 10^9) + (0.46 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 3.86 seconds
 * Relative Speed: `9.60 / 3.86` = `2.49`

8 Processor

 * `((0.46 * 10^9) + (0.23 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 2.25 seconds
 * Relative Speed: `9.60 / 2.25` = `4.27`

## B

1 Processor

 * `((2.56 * 10^9 * 2) + (1.28 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 10.88 seconds

2 Processor

 * `((1.86 * 10^9 * 2) + (0.91 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 7.93 seconds

4 Processor

 * `((0.91 * 10^9 * 2) + (0.46 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 4.31 seconds

8 Processor

 * `((0.46 * 10^9 * 2) + (0.23 * 10^9 * 12) + (2.56 * 10^8 * 5))/(2 * 10^9)`
 * Execution Time: 2.48 seconds

# Problem 3

~~~
sll $t0, $s0, 2      # $t0 = f * 4
add $t0, $s6, $t0    # $t0 = &A[f]
sll $t1, $s1, 2      # $t1 = g * 4
add $t1, $s7, $t1    # $t1 = &B[g]
lw $s0, 0($t0)       # f = A[f]
addi $t2, $t0, 4     # $t2 = &A[f+1]
lw $t0, 0($t2)       # $t0 = A[f+1]
add $t0, $t0, $s0    # $t0 = A[f+1] + A[f]
sw $t0, 0($t1)       # B[g] = A[f+1] + A[f]
~~~

C Code:

~~~c
B[g] = A[f+1] + A[f];
f = A[f];
~~~
