**Discussion 1/25 Minix Kernel**

See discussion slides on course website

# System Calls

Flow of control is controlled by system calls. These are written in C and C++

Posix standard:
 : Standard use of system calls in linux kernels

Pid = fork() -> create a child proceess identical to the parent

System calls should not be called directly. Should not call directly because
each OS could implement each call differently. Also, they are complicated. For
example, assembly language to open a file.

Kernel mode uses a different level of permission. User code is translated to
assembly and then put into kernel mode. The kernel can directly access the
hardware.

# System call tables

A array holds the system calls that you need. The OS maintains this table. For
adding one you can just tack it onto the end

# Actual System calls

TRAP signal tell the OS to switch from user mode to kernel mode.

Polling:
 : Used to repeadtly check if some condition has been reached.

Polling in this case would be to see if the I/O has been completed.

Interrupts:
 : Signal the processor when data transfer is complete.

# Rebuilding the Kernel Verison
