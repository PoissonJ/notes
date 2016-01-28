<!--Copy notes from red binder for chapter 2.1-->

## TSL Instruction

Hardware instructions that guarantee that the code is executed as one unit when
dealing with critical regions. Adds 1 to register to indicate a lock.

## Synchronization Problems

 - Critical Section: Only one process at a time can be inside.
 - Producer-Consumer Problem: Occurred when you read from a slow device. You
   want it to be read into memory before your processor tries to read it.
 - Bounded Buffer Problem: Not enough buffers. Multimedia devices today trying
   to stream video using a buffer frame.
 - Readers-Writers: Unlimited readers, but writers must access alone

### Producer-Consumer Solution

Bad solution: Check if the buffer is full after creating an item. If the buffer
is full, sleep until it is not full. Race condition occurs when incrementing
the count of items in the buffer. `count = count - 1;`. Both the producers and
consumers can be accessing the same buffer.

### Semaphores

Special type of shared memory.

Semaphores can only be declared and initialized. Only can be accessed by Up or
Down. **NO DIRECT ACCESS** Cannot find the value.

Up and down methods are generally synchronized (atomic) to prevent two
producers from entering the critical region.

Order matters. Mutex operations always should be close to the insert or remove.
This is to prevent the code from getting stuck.

#### Types and uses

 - Binary Semaphores: 1, semaphore is available. A 1 is used for mutual
   exclusion. A 0 is used for synchronization (Up(1) to indicate that the fork can
   be joined because the earlier process if finished) **Mutex**

 - Multivalued Semaphores: Take integer values >= 0. Used when you initialize
   an N where N represents the number of resources. We could have N buffers
   and the consumers need to know how many full buffers there are and if
   there are not any, we want to block. Producers in this situation would
   need to know the number of empty buffers.


All Synchronization problems follow:

 - General Process code (produce something, doe entry and exit code)
 - Launch all of them
 - Initialize them types
 - The code itself (entry and exit)

We can make the P-C problem occur concurrently if we mutually get an empty
buffer but then once the producer or consumer claims the buffer, we can allow
the program to keep running while the code on the buffer is completed.

# Monitors

Monitors are a *language construct*. Whatever a Monitor does depends upon the
programming language you are using. Monitors guarantee that only one process at
a time is executing in any entry procedure of that monitor.

*The Monitors we will use we assume will only wake up one process.*

## Condition Variables

**NOT SEMAPHORES**

Check to see if anyone is out there. If no process is waiting on the condition,
then signaling the condition will do nothing at all.

# Message passing

Bounded buffer problem that someone else has solved for you. Message queues are
a common OS construct.

The problem comes when you need to have the producer send a message to any of
the consumers. Want a Many to Many relationship instead of a one to one.

# The Dining Philosophers Problem

Eating is the critical section because there are the same number of forks as
there are plates so each Philosopher cannot eat at the same time.

# Process Scheduling

Used to schedule use of resources in the computer to various processes.

## When to schedule

 - When a process exits
 - When a process block on I/O, or a semaphore
 - New process
 - I/O interrupt
 - Clock interrupt

## Goals

 - Throughput: maximize the number of jobs per hour
 - Keeping the CPU busy
 - Fairness, balance
 - Fast requests

## Scheduling levels

 - Input
 - Admission scheduler: decides if the job gets resources
 - CPU scheduler (Short term): give the CPU to a certain process

## Scheduling Algorithm Measure

Turn-around time = `Finish time - arrival time`. This includes time spent
waiting for CPU

Mean Turn-around Time:
 : Averge TT over all jobs

Makespan:
 : Used for multiprocessor scheduling, it is the finish time for last job to
   finish - start time for set of jobs. How long does the whole thing take to
   finish.

Types:
 - Non-preemptive algs: used for if you have jobs that you know the runtime.
   The running job must give up the CPU voluntarily.
 - Shortest job frst (SJF)
 - FCFS (First come first serve)
 - Priority
 - Optimal: Uses knowledge to optimize turnaround time.

