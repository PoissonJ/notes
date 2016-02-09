# Tips

When making the system call and you want to read the value,

The mproc header defines the mproc table. Including that table gives you access
to the mproc  function. Or use find_proc. This is probably the better bet.

To know when you're out of bounds on the mproc array, there is a variable that
contains the maximum process id, maybe. Or it will return null (using
find_proc)

# Overview

One new entry in process table, integer value called shared val that is
initialized to 0

System call that gets and sets this shared value

# Testing

Once you have the system calls in place, you can write unit test to check if
sharred value can be set or gotten.

**usr/src/releasetools to compile**

Code that we changed with a text file explaining what we changed. Also a man
page for the C library

Passing pointers with m1_p1, ints with m1_i1
