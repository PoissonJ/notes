# Process, Discussion 3

Processes in the OS are when are run a program, it is a process. One proram per
process.

Processes are liniarized, none of them run at the same time. They just switch
very quickly. This switch normally happens when the process makes a system call
or needs to wait on an externam resource (Blocked).

**Minix is only running one process at a time.**

The OS minimizes the time it takes to execute the processes. It also makes sure
the processes are done in a quick time.

When you start the OS, the OS is the first process. This process then spawns
others by forking, and then executes something in the child process.

## Process termination

Normal exit:
 : returning 0 in c++

Error exit:
 : returning another number

Fatal error:
 : involuntary exit.

Killed by another proces:
 : `Kill` in UNIX

## Process Table

Data structure that the OS stores itself. Generally not accessible to the
programmer. Must use system call. Minix keeps a copy of this table in user
memory to avoid this.

# Assignment

1. /usr/src
2. modify servers/pm/mproc.h (this store the data strucrue you modify)
    pid_t mp_did;
3. modify servers/pm/forkexit.c (This is where the fork call in implemented)
    set mp_did = 2 * mp_did

    do_fork()
    do_srv_fork()
    MODIFY BOTH!

4. modify servers/procfs/pid.c
    buf_printf
    print out mp_did

5. make build && make install && reboot

6. cat /proc/<pid>/psinfo
