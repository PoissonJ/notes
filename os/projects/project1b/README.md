# Project 1b

Jonathan Poisson
poissonj@ufl.edu

## Execution

### Increment

> cat foo.txt
> 1
> 2
> 3
> 4
> 5
> 6
> 7
> 8
> 9
> 10

> ./increment 10000 foo.txt & ./increment 10000 foo.txt
> ./consecutive < foo.txt
> 11
> 11
> 12
> 12
> 13
> 13
> 14
> 14
> ... for a long time

### Safe Increment

> cat foo.txt
> 1
> 2
> 3
> 4
> 5
> 6
> 7
> 8
> 9
> 10

> ./safe_increment 10000 foo.txt config & ./safe_increment 10000 foo.txt config
> ./consecutive < foo.txt
>

## Discussion

The program safe_increment provides a way to run two processes at the same time
on a single text file while incrementing the last number in the text file for
an inputted number of times. This is accomplished using Peterson's algorithm.
The critical section for the program is the act of entering into the file,
reading the last value, incrementing by one and then writing the new value back
into the file. The flag and turn variables in Peterson's algorithm are created
by using each process' shared_val as the turn variable, and then computing the
XOR of the two shared_vals for the turn bit. While the turn bit is not
necessarily shared by each program, the computation of the XOR between the
different shared_vals allows for each process to have a copy of the turn bit
that matches the other process' value. The program that does not use this type
of mutual exclusion (increment) writes duplicates to the outputted text file as
both processes are reading and writing into the file at the same time.

### Possible bugs

Safe_increment seems to favor process 0 more than process 1, as process 0 will
always finish first in every run I tried. The program still, however, completes
the incrementing for both processes safely.

