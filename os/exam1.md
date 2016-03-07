Message passing is implemented in the kernel

CPU context switch time of 0.1ms
Job A: 1ms to start, (9ms I/O, 1ms) -> N times
 * This job will take 1 + 10*N to run
Job B: Same as A, how much time to complete Both jobs with order A,B and FCFS
 * Will take 2 + 10*N because B has to wait 1 ms for A starting
When looking at the context switch time, every time we switch from A to B we
need to add 0.1ms to both the start of A and the start of B
 * 2.2 + 10.1*N
