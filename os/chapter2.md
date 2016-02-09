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

# Readers Writers Solution

First come first serve.

# Process Scheduling

Used to schedule use of resources in the computer to various processes.

Nice is used to lower the priority of the current process

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

## Scheduling Algorithms

Types:
 - Non-preemptive algs: used for if you have jobs that you know the runtime.
   The running job must give up the CPU voluntarily.
 - Shortest job frst (SJF) NON PREEMPTIVE
 - FCFS (First come first serve) NON PREEMPTIVE and most simple
 - Priority
 - Optimal: Uses knowledge to optimize turnaround time.

Round Robin:
 : Jobs run in the order of arrival and go back to the end of queue when time
   is up. If a job arrives when the others job runs out, the new job gets the
   CPU. The time that each job gets depends on the policy you have in place.
   (Time quantum).

Shortest Remaining Time First:
 : Ready job that will finish first is the one that gets to run. PREEMPTIVE!
   Lots of work for the CPU, needs to figure out remaining time for each job.

Preemptive Priority:
 : If there is a job running at a low priority and a high priority arrives, the
   higher priority job runs. There can be different time quantums for each
   priority.

CTSS:
 : Attempts to approximate SRTF. Enter at queue 0, drops to next queue if time
   runs out. Each queue has a different quantum. The lowest queue gets priority
   (0 over 1). Processes move down queue once they run once in a certain queue.

**A context switch is switching between processes. The register values, memory
map... switches in the CPU.**

*With priority scheduling, we are generally not concerned about turnaround time.*

# Thread Scheduling

Thread is essentially an execution state within a process. Created and
destroyed easily because they share data that cooresponds to the process they
are contained in.

User Level Threads:
 : Simulate a machine in the process. The OS does not know about these threads.
   If one thread blocks (does I/O) the whole process is blocked by the OS.
   PROBLEM. Implementing semaphores avoids calling the OS, however.

Kernel Level Threads:
 : OS knows about them. Fixes the problem with one thread doing I/O as the OS
   can keep the process running. Kernel knows about the different processors in
   a multi-processor system which is not achievable in user level threads.

# Minix Structure

Polling checks for incoming messages. Messages are sent through either the pm,
fs, or rs folder first to handle the system call and detect any errors.

Bootstrap program "pulls yourself up by the bootstrap". Checks if the current
device is bootable and if it is not, move onto the next device.

Software interrupts are called SIGNALS
