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
    la $a0, str1          # Load string address into $a0
    li $v0, 4             # Load the value 4 into register $v0 which is for printing a string
    syscall               # Perform input/output

    la $a0, str2          # Load string address into $a0
    li $v0, 4             # Load the value 4 into register $v0 which is for printing a string
    syscall               # Perform input/output

    la $a0, str3          # Load string address into $a0
    li $v0, 4             # Load the value 4 into register $v0 which is for printing a string
    syscall               # Perform input/output

    li $v0, 5             # Read integer from console
    syscall               # Perform input/output

    move $t0, $v0         # Move user input to register $t0

    add $t1, $t0, $zero   # Create a temp variable that is the same as the user input

    li $t3, 10            # Load value of 10 into register t3
    li $t2, 0             # Load value of 0 into register t2

    LOOP:
    mul  $t2, $t2, $t3    # reverse = reverse * 10;
    div  $t1, $t3         # temp / 10
    mflo $t4              # Move result from temp / 10 into register t4
    mfhi $t5              # Move remainder from temp / 10 into register t5
    add  $t2, $t2, $t5    # reverse = reverse + (temp % 10)
    move $t1, $t4         # Move mflo from temp / 10 into temp
    beq  $t1, $zero, EXIT # if (temp == 0) end loop
    j    LOOP

    EXIT:
    beq $t0, $t2, PALINDROME     # if (num == reverse) go to PALINDROME block
    bne $t0, $t2, NOTPALINDROME  # if (num != reverse) go to NOTPALINDROME block

    PALINDROME:
    move $a0, $t0          # Load user input into register for printing
    li $v0, 1              # Load the value 4 into register $v0 which is for printing a string
    syscall                # Perform input/output

    la $a0, str4           # Load user input into register for printing
    li $v0, 4              # Load the value 1 into register $v0 which is for printing an int
    syscall                # Perform input/output

    li $v0, 10             # Exit
    syscall

    NOTPALINDROME:
    move $a0, $t0          # Load user input into register for printing
    li $v0, 1              # Load the value 4 into register $v0 which is for printing an int
    syscall                # Perform input/output

    la $a0, str5           # Load user input into register for printing
    li $v0, 4              # Load the value 4 into register $v0 which is for printing a string
    syscall                # Perform input/output

    li $v0, 10             # Exit
    syscall

