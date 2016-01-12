# Operating Systems Generations

## Generation 1

 * Single user and single application at a time
 * Users had to clear out the memory when done

## Generation 2

 * Use of batch systems
 * User not the operator as in they do not get to touch the machine.
 * Job control language (JCL)
 * One job at a time in the 50's and multi in the 60's

## Generation 3

 * Timesharing systems, each user is given the machine to themselves
 * Similar to ssh into a server

## Generation 4

 * Personal computers

## Generation 5

 * Nerwork operating systems

## Generation 6

 * Distributed operating Systems, multiple machines

## Generation 7

 * Cooperative Autonomous Systems
 * Independent systems, (Kayak to find a hotel)
 * Cloud computing, "as a service"

# Processes

Processes can start other processes (shell).

Creates a tree like structure. File structures are also in a tree like
structure

Processes can communicate through a `pipe`

Processes have three basic segments

 * Instructions (text segment)
 * Data
 * Stack

# Shell

Shell is in an infinite loop

Return value of fork call is either 0 if it is a child or the process id

dup command starts at the top of the PFT and assigns the first open slot,
useful for redirecting I/O to a pipe for example.
