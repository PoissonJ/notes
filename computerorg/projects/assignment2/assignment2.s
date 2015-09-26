# Assignment 2
# Name: Jonathan Poisson
# Class: CDA 3101
# Date: 09/17/15

# Data declarations
    .data
str1: .asciiz "Enter first integer n1: "
str2: .asciiz "\nEnter second integer n2: "
str3: .asciiz "The greatest common divisor of n1 and n2 is "
str4: .asciiz "The least common multiple of n1 and n2 is "

.globl main
.text

main:
    la $a0, str1          # Load string address into $a0
    li $v0, 4             # Load the value 4 into register $v0 which is for printing a string
    syscall               # Perform input/output

    li $v0, 5             # Read integer from console
    syscall               # Perform input/output

    move $t0, $v0         # Move user input to register $t0

    la $a0, str2          # Load string address into $a0
    li $v0, 4             # Load the value 4 into register $v0 which is for printing a string
    syscall               # Perform input/output

    li $v0, 5             # Read integer from console
    syscall               # Perform input/output

    move $t1, $v0         # Move user input to register $t1

    move $a0, $t0         # Move user input to argument storage
    move $a1, $t1

    jal GCD               # Call GCD function

    move $a0, $v0         # Move answer form GCD into register for printing
    li $v0, 1             # Load the value 4 into register $v0 which is for printing an int
    syscall               # Perform input/output

    GCD:                  # Calculates the greatest common divisor
    addi $sp, $sp, -12    # Adjust stack for three items
    sw $ra, 8($sp)        # Save return adress
    sw $a0, 4($sp)        # Save argument n1
    sw $a1, 0($sp)        # Save argument n2

    bne $t1, $zero, GCD1  # Test for (n2 != 0)

    add $v0, $zero, $a0   # If not, result is n1
    addi $sp, $sp, 12     # Pop three items from the stack
    jr $ra                # Return

    GCD1:                 # Else
    div $a0, $a1          # Divide n1 and n2
    mfhi $a0              # Move remainder to $a0
    jal GCD               # Recursive call

    lw $a0, 0($sp)        # Restore original n1
    lw $a1, 4($sp)        # Restore original n2
    lw $ra, 8($sp)        # Restore return address
    addi $sp, $sp, 12     # Pop three items from the stack
    jr $ra                # Return
