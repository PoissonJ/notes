# Problem1

## A

 * P1: `3.2 / 1.6` = `2   * 10^9` Instructions per second
 * P2: `2 / 1.25`  = `1.6 * 10^9` Instructions per second
 * P1: `1 / 4`     = `1   * 10^9` Instructions per second

The highest performing processor is *Processor 1*

## B

P1:

 * clock cycles = 5 seconds * (3.2 * 10^9) = 16 * 10^9
 * instruction count = 16 * 10^9 / 1.6 = 10 * 10^9

P2:

 * clock cycles = 5 seconds * (2.0 * 10^9) = 10 * 10^9
 * instruction count = 10 * 10^9 / 1.25 = 8 * 10^9

P3:

 * clock cycles = 5 seconds * (4.0 * 10^9) = 20 * 10^9
 * instruction count = 20 * 10^9 / 4.0 = 5 * 10^9

## C

P1:

 * Old Exection Time = (10 * 10^9 * 1.6) / (3.2 * 10^9)  = 5
 * 5 * .8 = (10 * 10^9 * 1.6 * 1.15) / Clock Rate
 * Clock Rate = 4.6 GHz

P2:

 * Old Exection Time = (8 * 10^9 * 1.25) / (2.0 * 10^9)  = 5
 * 5 * .8 = (8 * 10^9 * 1.25 * 1.15) / Clock Rate
 * Clock Rate = 2.875 GHz

P3:

 * Old Exection Time = (5 * 10^9 * 4) / (4 * 10^9)  = 5
 * 5 * .8 = (5 * 10^9 * 4 * 1.15) / Clock Rate
 * Clock Rate = 5.75 GHz


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

# Problem 4

## A

 * sll $t2, $t0, 24  #$t2=AA00 0000
 * or $t2, $t2, $t1  #$t2=BA34 5678

## B

 * sll $t2, $t0, 4   #$t2=AAAA AAA0
 * andi $t2, $t2, -1 #$t2=AAAA AAA0

## C

 * srl $t2, $t0, 3  # $t2=1555 5555
 * andi $t2, $t2, 0xFFEF #$t2=0000 5545

# Problem 5

## A

Runs through the loop 10 times and adds 2 to $s2 each time so $s2 = 20

## B

~~~c
// Use A as $s1, $s1 was not used in the code so I am assuming that $s1 is 2
// for the C  code
int A = 2;

while (i > 0) {
    i -= 1;
    B += A;
}
~~~

# Problem 6

~~~
f:
addi $sp, $sp, -12  # Allocate space on the stack
sw $ra, 0($sp)      # Save return address
sw $a2, 4($sp)      # Save c
sw $a3, 8($sp)      # Save d
jal func            # Call func(a,b)
move $a0, $v0       # Move result to $a0
lw $t0, 4($sp)      # Load c
lw $t1, 8($sp)      # Load d
add $t2, $t0, $t1   # Add c and d
move $a1, $t2       # Move c+d into second argument
jal func            # Call func(func(a,b), c+d)
lw $ra, 0($sp)      # Load return address
addi $sp, $sp, 12   # Restore stack space
jr $ra              # Return to caller
~~~

# Problem 7

 * 176 = 1011 0000 while ignoring the leading 0
 * 121 = 0111 1001
 * 176 = 1 0011 0111

*Overflow*

# Problem 8

 * 176 = 1011 0000 while ignoring the leading 0
 * -121 = 1000 0111
 * 176 = 1 0011 0111

*Overflow*

# Problem 9


# Problem 10

 * Convert sign to 0
 * Convert 69 to binary
    + 100101

| .25 * 2 = *0*.5
| .5 * 2  = *1*.0
| 0 * 2   = *0*.0

 * 1000101.010  Shift decimal point left 6
 * bias = 127+5 = 132
 * 133 in binary
    + 10000101
 * Combine
     + 0100000101000101010
 * Add on 0's to meet 32 bit requirement

Final Answer:
  : 01000010100010101000000000000000
