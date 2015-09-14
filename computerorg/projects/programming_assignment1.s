# First SPIM Assignment
    # Program 1
    # Name: Jonathan Poisson
    # Class: CDA 3101
    # Date: 09/17/15

# Data declarations
    .data
str1: .asciiz "Programming assignment 1 for CDA3101\n"
str2: .asciiz "This palindrome checker only deals with postive integer number.\n"
str3: .asciiz "Enter a number to check if it is a palindrome or not.\n"
str4: .asciiz " is a palindrome number.\n"
str5: .asciiz " is not a palindrome number.\n"

.globl main
.text

main:
    la $a0, str1        # Load string address into $s0
    li $v0, 4           # Load the calue 4 into register $v0 which is for printing a string
    syscall             # Perform input/output

    la $a0, str2        # Load string address into $s1
    li $v0, 4           # Load the calue 4 into register $v0 which is for printing a string
    syscall             # Perform input/output

    la $a0, str3        # Load string address into $s2
    li $v0, 4           # Load the calue 4 into register $v0 which is for printing a string
    syscall             # Perform input/output

    li $v0, 5           # Read integer from console
    syscall             # Perform input/output

    move $t0, $v0       # Move user input to register $t0

    add $t1, $t0, $zero # Create a temp variable that is the same as the user input

    LOOP:
    mul $t2
    bne $t1, $zero, EXIT # if (temp != 0) end loop

    EXIT:
