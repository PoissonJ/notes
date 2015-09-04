# Introduction to Computer Organization Exam 1

# Computer Abstractions and Technology

## The computer revolution

Moore's Law
  : chip integration is doubled every **18** months

Computer processors become more and more powerful and take less power

## Classes of Computers

Personal computers

 * General purpose
 * Subject to cost/performance tradeoff

Server computers

 * Small to building sized

Supercomputers

 * Single sytem which can solve a particular application very fast

Embedded computers

 * Hidden as components of the system
 * Stringent power/performance/cost constraints

## The PostPC Era

Personal Mobile Device

 * Battery operated (Phones)

Cloud Computing

 * Warehouse scale computers (WSC)
 * Software as a Service (SaaS)
 * Amazon and Google

## 8 Great Ideas - Architect

 * Moore's Law
 * Abstraction to simplify design
 * Common case fast
 * Parallelism
 * Pipelining
 * Prediction
 * Hierarchy of memories
 * Dependability

## Below Your Program

Applications Software
  : Written in high-level language
System software
  : compiler...
Hardware
  : processor...

### Levels of Program Code

High-level --> Assembly language --> Hardware representation (10101001)

## Components of a computer

All Computers have the same components

 * Input/output
 * Processor
 * Memory

## Inside the Processor (CPU)

Datapath:
  : performs operations on data
Control:
  : sequences datapath, memory
Cache memory:
  : Small fast SRAM memory for immediate access to data

## Summary

Abstraction
  : Helps us deal with complexity

Instruction set architecture (ISA)
  : The hardware/software interface

Application binary interface
  : The isa plus the hardware

## Safe place for data

Volatile main memory
  : Non permanent

 * Loses instruction and data when poweroff
 * DRAM

Non-volatile secondary memory

 * Magnetic disk
 * Solid-state disk
 * Optical drive

## Networks

 * Communication, resource sharing, nonlocal access...

Intel Core i7 Wafer
  : 300mm wafer, 280 chips, 32nm technology. Each chip is 20.7 x 10.5 mm

## Relative Performance

Define Performance = 1/Execution Time

> X is **n** times faster than Y

    Performacncex/performacey = Execution timey / Execution timex = n

Example:

    10s on A, 15s on B
    Execution timeb / execution time a = 15s/10s

### Measuring Execution time

 * Elapsed time

 * CPU time

    + Number of Executed Instructions

CPU Time formula

    CPU Time = Instructions/Program * Clockcycles/instruction *
    Seconds/Clock cycle

### CPU Clocking

Operation of digital hardware governed by a constant-rate clock

Clock Period
  : Duration of a clock cycle

Clock Frequency

    CPU TIME = CPU Clock Cycles * Clock Cycle Time

Performance improved by

 * Reducing total number of clock cycles
 * Increasing clock rate



## CPI in More detail

CPI:
  : How much time on average to execute each cycle (Cycle per instruction)

Affected by programming language, compiler, algorithms, instruction set
architecture...

*Computer Processor organizationa and microprocesser affects the speed*

## Reducing Power

The power wall:

 * We cannot reduce voltage further
 * We cannot remove more heat

Uniprocessor Performance is constrained by power, instruction-level
parallelism,  and memory latency

##Multiprocessors

More than one processor per chip

Requires explicitly parallel programming

## Concluding Remarks

 * Cost/performance is improving
 * Hierarchical layers of abstraction in both hardware and software
 * ...

# Chapter 2 Instruction Set

 * Appendix A: MIPS Instruction Set
 * Appendix B: Digital Logic Basics

## MIPS Examples

`add a, b, c # a gets b + c`

 * Add and Subtract, three operands
 * `add` is called opcode and the variables are called operands
 * `#` is a comment
 * *Design Principle 1:* Simplicity favors regularity
     + Regulatiry makes implementation simpler
     + Simplicity enables higher performance at lower cost

Example:

 * C code:

~~~c
f = (g+h) - (i+j);
~~~

 * MIPS

| add t0, g, h
| add t1, i, j
| sub f, t0, t1 `# Put into f the subtraciton of t0 and t1`

 * Operands can be in: Register, memory and immediate

Example:

 * C code:

~~~c
g = h + A[8]
~~~

    + g in $s1, h in $s2, base address of A in $s3

 * Compiled MIPS
     + Index 8 requires offset of 32
        - 4 Bytes per word. 8,  4 byte words. 8 * 4 = 32

| lw  $t0, 32($s3)    `# Load word that is already is $s3`
| add $s, $s2, $t0

Example:

 * C code:

~~~c
A[12] = h + A[8]
~~~

    + g in $s2, base address of A in $s3

 * Compiled MIPS
     + Index 8 requires offset of 32

| lw  $t0, 32($s3)    `# Load word that is already is $s3`
| add $t0, $s2, $t0
| sw  $t0, 48($s3)    `# Store word

**No Subtract Method** Instead must add a negative value

**To Move From One Register To Another**, use the constant zero

|add $t2. $s1, $zero


### Register Operands

Register:
  : Data moves in and out of Register. Register can be accessed very fast due
    to small number of them. Data and the register is simple. *Design Principle
    2:* Smaller is faster. Register can do simple arithimetic for example.

 * Registers are accessed from the MIPS Register Table. For example, $zero is
     reister 1 and $t0 is register 5, the first register you can use

### Memory

Memory is a storage location and given its address, you can access the memory

 * Registers are faster to access than memory
 * Operating on memory data requires lods and stores
 * Compiler must use registers for variables as much as possible

#### Endians and Alignment

&nbsp;

Byte address is 8 locations. Word-aligned word at byte address must be at 4 or
0. Halfword-aligned word at 2. Byte-aligned (non-aligned) word, at byte address
1.

Big-endian:
  : Most significant byte "first"

Little-endian:
  : Least significant byte "first"


