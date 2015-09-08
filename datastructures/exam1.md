# Intro

Comparison Count. Pick an instance characteristic .... n

    For insertion sort, pick n= number of elements to be sorted.

Step Count
  : A step is an amount of computing that does not depend on the instance
    characteristic n

steps per execution is not always 0 or 1. For example

> x = sum (a,n)


> **Algorithimic imporvement is more useful than hardware imporvement**


# Performance Measurement

Uses:
 * Determine practicality of algorithm
 * Predict run time on large instance
 * Compare 2 algorithms that have different asymptotic complexity
    O(n) and O(n^2)

## Limitations of Analysis

 * Does not account for constant factors
 * Constant factor may dominate. (1000n vs n^2)

> Modern computers have a hierarchical memory organization with different
> access time for memory at different levels. Main memory can be 100x slower
> than the cache. analysis does not account for this

Need:

 * Worst case data
 * Best case data

### Timing in C++

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


# Data Structures

Design:
  : In every activity, there are a number of possible solutions. We must pick
    one when implementing software. Sometime the solution is not optimum for
    one solution. Design is the process of selecting one element in a viable
    solution space.

Data Object:
  : Set or collection of instances. Days of the week or A list of numbers.
    Could be related or not, doesn't matter

> The relationships are usually specified by specifying operations on one or
> more instances. Data Structures are a set of data that you do operations to.

Data Structure Specification

 * Language independent
    + Abstract Data Type
    + Just English telling what each method of the class will do
 * C++
    + Abstract Class
    + Purely virtual

## Linear (or Ordered) lists

Things one after the other

> (e0, e1, e2....e(n-1))

 * ei denotes a list element
 * n >= 0 is finite
 * List size is n
 * e0 is the zero'th (or front) element in the list

Example:

 * (Jack, Jill, Bob)

Operations

 * Determine list size
 * Get(given Index)
 * IndexOf(element) - Items could be repeated, however, which would yield an
     incorrect index. -1 is returned if the item is not found
 * Erase(Index)
 * Insert(Index, Element)- nice to have the arguments go in natural english
     order "Insert into slot 5 'a'"
    + Use a for loop to shift everything over to the right and then input the
        argument

Extending a C++ class -
  : (From an already created C++ pure virtual class)

~~~c
template<class T>
class arrayList: public linearList<T> {
    //Code for all abstract methods of a linearList must come here
}
~~~

### Linear List Array Representation

Use a one-dimensional array element[ ]

**L = (a,b,c,d,e)**

Store element i of list in element[i]

Representation of the list include:

 * Mapping from right to left
 * Mapping that skips every other position
 * Wrap around mapping
    + Useful for Queues and Stacks

### Potential Problems

We do not know how many elements will be in the list, therefore we could run out
of allocated memory. Therefore, we must pick an initial length and dynamically
increase as needed. Use another variable to store current length of the array

Solution:

 * First create a new and larger array

~~~c
T * new Array = new T[15];
// There will be a pointer to the new array
~~~

 * Now copy elements from old array to new one
 * Finally, delete old array and rename new array

~~~c
delete[] element;
element = new Array;
arraylength = 15;
~~~

How Big should the new array be?
  : At least 1 more than current array length. Cost of increasing array length
    when array is full is theta(old length). Cost of n insert operations done on
    an initially empty linear list increases by theta(n^2). THIS IS VERY
    EXPENSIVE!

Space actually needed:
  : 2 * newLength - 1. Or, you could double the array length. In this case, the
    time for n inserts is linear, theta(n), but this will be 2n+1 which is why we
    use the first formula

**C++ uses multiplicative power of 1.5 in its implementation**

### Code

> General purpose implementation

**Create an Empty List**

~~~c
arrayLinear<int>a(100), b;
arrayLinear<double>c(10), d;

linearList<int>*d = new arrayList<int>(1000);
linearList<char>*f = new arrayList<char>(1000);

// F is a pointer to a type arrayList. The object holds a pointer
// and variables for the max size and size to the list
~~~

** Using the List**

~~~c
cout << a.size() << endl;
a.insert(0, 2);
d->insert(0, 4);
a.output();
cout << a << endl; // Operator overloading

a.erase(0);
if(a.empty()) a.insert(0, 5);
~~~

**Array of Linerar List**

~~~c
lineraList<int>*x[4];
x[0] = new arrayList<int>(20);
x[1] = new chain<int>();
x[2] = new chain<int>();
x[0] = new arrayList<int>(15);

for (int i = 0; i < 4; i++) {
    x[i].insert(0, i);
}
~~~

**The Class arrayList**

~~~c
// include statements come here
using namespace std;
template<class T>
class arrayList : public linearList<T> {
    public:
    // Constructor, copt constructor and destructor
    arrayList(int initialCapacity = 10);
    ~arrayList)_ {delete [] element;}

    protected:
    void checkIndex(int theIndex) const;
        // throw ilegalIndex if theIndex invalid
    T* element;  // 1D array to hold list elemtnes

    ...
}
~~~

*Be careful with `const` placement. If placed at the end, the method cannot
change the object for example.*

**The whole purpose if to create little, simple methods that reduce the overall
complexity of the class. If your method is 20+ lines long, you are asking for
trouble.**

## Iterator

**Allows you to iterate through and have access to each of the elements in a
data structure.**

Bidirecitonal Iterator:
  : Allows both forward and backward iteration

 + {iterator(T * the Posiion)}

### Iterator class

 + assume bidirecitonal
 + assume arrayList has begin() and end() methods

~~~c
arrayList<int>::iterator xHere = x.begin();
arrayList<int>::iterator xEnd = x.end();
for (; xHere != xEnd; xHere++) {
    // examine xHere
}
~~~

## Linked List

**Nodes connected by pointers**

 * A linked list in which each node represents one elemet

`Chain` is the class while `ChainNode` is a `struct` in the class

&nbsp;

&nbsp;

**Visual Representation**

 ----
 ptr
 ----
 Attributes
 **
 ---

When **erasing** a node, you change where the pointer pointing to that node is
pointing. However, first you have to delete the node so you don't lose access
to it and have a memory leak

Destructors will take care of the features in an object but will not delete the
pointer to the object itself. That's what the `delete` keyword does.
