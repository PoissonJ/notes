<!--Copy notes from red binder for chapter 2.1-->

## TSL Instruction

Hardware instructions that guarantee that the code is executed as one unit when
dealing with critical regions. Adds 1 to register to indicate a lock.

## Synchronization Problems

 - Critical Section
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
Down. **NO DIRECT ACCESS**

#### Types and uses

 - Binary Semaphores: 1, semaphore is available. A 1 is used for mutual
   exclusion. A 0 is used for synchronization (Up(1) to indicate that the fork can
   be joined because the earlier process if finished)
