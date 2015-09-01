# Environment

Compiler:
  : gcc or g++ compiler will work.

# First C Program - Chapter 1

~~~c
 #include<stdlib.h>
 #include<stdio.h>
int main() {
    printf("Hello world!");
    return 0;
}
~~~

# C Fundamentals - Chapter 2

## Program: Printing a Pun

~~~c
 # include <stdio.h>

int main(void) {
    printf("To C, or not to C: that is the question.\n");
    return 0;
}
~~~

The `#include` is a preprocessor directive

### General Form of a Simple Program

Simple C programs have the form:

    directives

~~~c
int main(void) {
    statements
}
~~~

stdio:
  : Standard C I/O Library

main function:
  : Gets called automatically and is required

Statements:
  : Command to be executed when the program runs



## Macro Definition

Using a feature know as *macro definition*, we can name this constant

`#define INCHES_PER_POUND 166`

or

`#define RECIPROCAL_OF_PI (1.0f / 3.14159f)`

## Variable Names

Cannot use:

 * Number only
 * Start with a number
 * '-'

*C is case sensitive*

# Formatted Input/Output - Chapter 3

## Printf
printf is %m.p(f or d) where m is the minimum field width and p is number of decimals
to print and the (f or d) corresponds to the number of either decimals (f) or
ints (d) to print. If there are more ints (d) than there are in the actual
number, 0's will be added on when printing.

`example: printf("%.3d", 40)  --->   040

minimum field width:
  : The amount of space taken on the screen. A negative m means that it will be
    leaning left or left justified

%d :
  : placeholder for int

`printf("height %d\n", height)`

%f :
  : placeholder for floating point

`printf("Profit: $.2f\n", profit)`  This prints 2 decimal points`

`printf can handle arithmetic("%d\n", height * length * width);`

&nbsp;

### Escape Sequences

 Result      Characters
 ------      ---------
 Alert(bell) `\a`
 tab         `\t`
 backspace   `\b`
 newline     `\n`
 ----------------


## Scanf

 * scanf is the C library's counterpart to printf
 * scanf requires a format string to specity the appearance of the input data
 * Example of using scang to read an int value:

~~~c
scanf("%d", &i);
 /* Reads an integer and stores into i */
~~~

 * Use "%f" for floating point number
 * Must use the variables address when reading into a variable
