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

    int main(void) {
        statements
    }

stdio:
  : Standard C I/O Library

main function:
  : Gets called automatically and is required

Statements:
  : Command to be executed when the program runs

## Printf

%d :
  : placeholder for int

`printf("height %d\n", height)`

%f :
  : placeholder for floating point

`printf("Profit: $.2f\n", profit)`  This prints 2 decimal points
