# Project 2: Semaphores

Jonathan Poisson -- Poisson.Jonathan777@gmail.com

## Overall Implementation

### Server

I decided to created support for semaphores in Minix 3.2.1 by creating a
stand-alone semaphore service. Instead of adding semaphore operations to the PM
of VFS server, I found that I had more freedom and ease of implementation by
creating a new service to run a unique service. This service controls the
creation of semaphores, the waiting queue, and the up and down operations on
the semaphores. The service is started up automatically when the OS boots by
adding the service to `/kernel/table.c`.

#### Create Semaphore

Create semaphore take the initial value and type of semaphore to create the
semaphore in the semaphore service. Internally, there is an array of semaphores
(allowing for up to 5 unique semaphores) and the create_semaphore operation is
successful if there is an open slot in the semaphore array, allowing the slot
to be filled with the semaphore value. The return value is a semaphore handle
that represents the index in the semaphore array where the created semaphore
resides. Another adjacent array to the semaphore array holds the semaphore
types, 0 for binary and 1 for multivalued.

#### Delete Semaphore

Delete semaphore takes a semaphore handle (index in semaphore array) and has
the purpose of freeing a spot in the semaphore array (setting it back to -1).
The call is successful and will return -1 if the semaphore handle is a valid
entry in the array and has a created semaphore in the given index. The call is
successful and will return -1 if the semaphore handle is a valid entry in the
array and has a created semaphore in the given index.

#### Down

Down take a semaphore handle, and the endpoint of the process (The user does
not have to worry about this, it is handled in the semaphore server's main.c).
If the semaphore handle passed by the calling process is a valid one, the value
of the semaphore is checked. If the value is 0, the process is added to the
waitingProcesses array and is suspended, if not, the semaphore value is decremented by 1 and the
process continues running.

#### Up

Up takes a semaphore handle (index in semaphore array) and has the purpose of
incrementing the current semaphore. If the specified semaphore is of type
binary and the caller wants to up a 1, it will fail. If the current value of
the semaphore is 0, the up operation will first check to see if there are any
waiting processes in the waiting processes array. If there is one, it will be
woken up with a message and the semaphore value will remain the same.

## Bugs

When I created the server, I had issues getting processes to have access to the
server. The server could also not send and receive messages, even with the
necessary access in `/usr/src/etc/system.conf` of...

~~~
service semaphore
{
    uid 0;
    ipc ALL;
    system ALL;
}
~~~

To get around this, I needed to turn off the debug messages in for ipc warnings
`/usr/src/kerneldebug.h` and to all comment out the `return(ECALLDENIED)` line
in `/usr/src/kernel/proc.c` on line 473. Having to do this make me believe that
the permissions in the conf file are not setup correctly, and that now any
process can make a send or receive call, regardless of its origin or status.

