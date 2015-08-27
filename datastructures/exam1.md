# Data Structures Exam 1

Comparison Count. Pick an instance characteristic .... n

    For insertion sort, pick n= number of elements to be sorted.

Step Count
  : A step is an amount of computeing that does not depend on the instance
    characteristic n

steps per execution is not always 0 or 1. For example

> x = sum (a,n)


> **Algorithimic imporvement is more useful than hardware imporvement**


## Performance Measurement

Uses:
 * Determine practicality of algorithm
 * Predict runt ime on large instance
 * Compare 2 algorithms that hace differeny asymptotic complexity
    O(n) and O(n^2)

### Limitations of Analysis

 * Does not acount for constant factors
 * Constant factor may dominate. (1000n vs n^2)

> Modern computers have a hierarchical memory organization with different
> access time for memory at different levels. Main memory can be 100x slower
> than the cache. nalysis does not account for this

Need:

 * Worst case data
 * Best case data

#### Timing in C++

~~~c
double clocksPerMillis =
    double(CLOCKS_PER_SEC) / 1000;
// clock ticks per millisecond

clock_t startTime = clock();

// Code to be timed comes here
// Need to do this while clock() - startTime < 1000

double elapsedMillis = (click() - startTime)
~~~

This could be an issue when the amount of time is 1.5 clock ticks or something
like that.

Clock accuracy, assume 100 clicks. Repeat work many times to bring total time
to be >= 1000 ticks. This makes the accuracy +- 10%. A very short process could
register as 0 ticks.

When measuring sorting, must use same unsorted array each time

UNIX `time MyProgram` takes into account busy cores doing other tasks


## Data Structures

Data Object
  : Set or collection of instances. Days of the week or A list of numbers.
    Could be related or not, doesn't matter

> The relationshjips are usllay specified by specifying operations on one or
> more instances. Data Structures are a set of data that you do operations to.

### Linear (or Ordered) lists

Things one after the other

> (e0, e1, e2....e(n-1))

 * ei denotes a list element
 * n >= 0 is finite
 * List size is n
 * e0 is the zero'th (or front) element in the list

Example
 * (Jack, Jill, Bob)

Operations

 * Determine list size
 * Get(given Index)
 * IndexOf(element) - Items could be repeated, however, which would yield an
     incorrect index. -1 is returned if the item is not found
 * Erase(Index)
 * Insert(Index, Element)- nice to have the arguments go in natural english
     order "Insert into slot 5 'a'"

