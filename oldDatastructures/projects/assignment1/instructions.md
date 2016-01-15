COP 3530, Fall 2015
Data Structures and Algorithms
Assignment 1: The Josephus Problem
Due: September 21, 2015, 11:59 p.m
Description:

    A group of n candidates are standing in a circle waiting to be chosen as
    the winner. They are consecutively numbered 0 to n-1. Every k-th person is
    removed from the circle. This process will continue around the circle until
    one person is left. The goal for this assignment is to simulate the process
    so that you can determine the winner. To accomplish this task, you will
    implement and simulate this process with a singly circular linked list.

This assigment is divided into 3 parts as follows:
    1. Implementing a working Circular Singly Linked List Class ( Source Code ) – 60 points
    2. Simulating the Josephus Problem as described above. – 30 points
    3. Providing documentation on your source code. – 10 points

Part I - 60 Points
Implement a Templated Circular Singly Linked List Class
The class must implement the following operations:
    1. Constructor for creating the List
    2. Destructor for safely deleting the List
    3. Inserting an element at index x, where x is read from stdin
    4. Deleting an element at index x, where x is read from stdin
    5. Printing out the list in sequential order(from the head to the item before the head).
    6. Printing the element at index x.

Each operation accounts for 10 points.
Part II - 30 Points
Write a C++ program “josephus.cpp”, that wil test the functionality of your
Circular Class, and test the functionality of your Josephus problem solution.
Based on input, youir program must insert an element at a desired index, or
delete the element at a desied index, or print the entire list, or print the
element at a desired index, or simulate the Josephus problem.  The input begins
with an integer n specifying the number of commands to follow. After that line
there will be n lines with a command on each line, of the following form:

    I n i => Insert element n at the ith position
    D i => Delete the element at the ith position
    S => Print entire List sequentially
    P i => Print the element at the ith position

To test the Josephus simulation, accept a command of the following form:

    J n k 9 13 7 => Simulate the Josephus problem

n is the number of insertions into the list. k is the parameter to the Josephus
problem, in which every k-th element will be removed. The subsequent n numbers
are the elements to insert at the head of the list, before starting the
Josephus simulation.  Note:  the “=> blah”  text above is for explanatory
purposes, and not part of the actual input (in case you were wondering).

Sample input is as follows:

19
I 1 0
I 2 1
I 3 2
I 4 3
I 5 4
I 6 5
I 7 6
I 8 7
I 9 8
I 10 9
S
I 0 2
S
P 5
D 5
P 5
S
P 165
J 3 2 34 23 22


The output for the above sample input should be as follows:
thunder:29% ./josephus < input

[1,2,3,4,5,6,7,8,9,10]
[1,2,0,3,4,5,6,7,8,9,10]
5
6
[1,2,0,3,4,6,7,8,9,10]
Out of Range error
[23,1,0,4,7,9,22,2,6,10,3,34,8]

Note: the items printed by the J command are the elements as they are being deleted during the Josephus simulation, with the last one being the winner.
We will test your submissions by following these steps (commands on thunder.cise.ufl.edu):
    1. tar xvf “<LastName_FirstName>_UFID.tar”
    2. make
    3. ./josephus < our_input

Part III - 10 Points
Please include a PDF document containing your test cases, test results, and any
special diagnostics you utilized. This file shall be named
<LastName_FirstName>_UFID_Report.pdf
Deliverables:
Your submission tarball(.tar archive file) should be named
<LastName_FirstName>_UFID.tar and must contain the following files:
josephus.cpp, Makefile, and <LastName_FirstName_UFID_report.pdf A PDF document
containing your own test cases, test results, and any special diagnostics you
utilized. This file shall be named <LastName_FirstName>_UFID_Report.pdf

Grading Rubric:
    Part I - 60 Points
        - 10 Points for each operation
    Part 2 - 30 Points
    Part 3 - 10 Points

PLEASE NOTE that ALL submissions MUST compile on thunder.cise.ufl.edu by using
your Makefile. It is highly reccomended that you upload your source code to
your CISE account and test it on the thunder. Secure Remote Access to CISE
machines is available. Please visit this link for more information,
https://www.cise.ufl.edu/help/access/remote. We will not debug your source code
or makefile. Please refer to and make note of the submission rules and policies
before submitting, http://cise.ufl.edu/class/cop3530fa15/SubmissionRules.htm.
After submitting on Canvas, you should verify that your submission was
successful by downloading it from Canvas (to a separate location), and
successfully un-tarring, compiling, and running it. YOU ARE NOT DONE UNTIL YOU
DO THIS.
