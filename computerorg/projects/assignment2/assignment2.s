# Assignment 2
# Name: Jonathan Poisson
# Class: CDA 3101
# Date: 09/29/15

# Data declarations
    .data
str1: .asciiz "Enter first integer n1: "
str2: .asciiz "Enter second integer n2: "
str3: .asciiz "The greatest common divisor of n1 and n2 is "
str4: .asciiz "\nThe least common multiple of n1 and n2 is "

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
    move $t2, $v0         # Store the answer from GCD in temp

    move $a0, $t0         # Move user input to argument storage
    move $a1, $t1

    jal LCM               # Call LCM function
    move $t3, $v0         # Store the answer from LCM in temp

    la $a0, str3          # Load string into print address
    li $v0, 4             # Load the value 4 into register $v0 which is for printing an int
    syscall               # Perform input/output

    move $a0, $t2         # Move answer from GCD into register for printing
    li $v0, 1             # Load the value 4 into register $v0 which is for printing an int
    syscall               # Perform input/output

    la $a0, str4          # Load string into print address
    li $v0, 4             # Load the value 4 into register $v0 which is for printing an int
    syscall               # Perform input/output

    move $a0, $t3         # Move answer from LCM into register for printing
    li $v0, 1             # Load the value 4 into register $v0 which is for printing an int
    syscall               # Perform input/output

    li $v0, 10             # Exit
    syscall

GCD:                      # Calculates the greatest common divisor
    addi $sp, $sp, -12    # Adjust stack for three items
    sw $ra, 8($sp)        # Save return adress
    sw $a0, 4($sp)        # Save argument n1
    sw $a1, 0($sp)        # Save argument n2

    bne $a1, $zero, GCD1  # Test for (n2 != 0)

    add $v0, $zero, $a0   # If not, result is n1
    addi $sp, $sp, 12     # Pop three items from the stack
    jr $ra                # Return

GCD1:                     # Else
    div $a0, $a1          # Divide n1 and n2
    move $a0, $a1         # Move n2 to n1
    mfhi $a1              # Move remainder to $a1
    jal GCD               # Recursive call

    lw $a0, 0($sp)        # Restore original n1
    lw $a1, 4($sp)        # Restore original n2
    lw $ra, 8($sp)        # Restore return address
    addi $sp, $sp, 12     # Pop three items from the stack
    jr $ra                # Return

LCM:                      # Calculates the least common multiple
    addi $sp, $sp, -12    # Adjust stack for three items
    sw $ra, 8($sp)        # Save return adress
    sw $a0, 4($sp)        # Save argument n1
    sw $a1, 0($sp)        # Save argument n2

    mul $t0, $a0, $a1     # Multiply n1 and n2 into temp register
    jal GCD               # Perform GCD with n1 and n2
    div $t0, $v0          # Divide the result from GCD with temp register
    mflo $v0              # Save division result to return register
    lw $ra, 8($sp)        # Load return address from stack
    addi $sp, $sp, 12     # pop 3 items from the stack
    jr $ra                # return
