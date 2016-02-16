# Chapter 3

*Slow I/O devices, we want to concentrate those to accomplish a fast task*

*The DMA is a producer consumer problem*

*Review: I/O controller, device drivers, DMA*

## Deadlock

*A set of process is deadlocked that only another process can solve and both
processes are relying on eachother*

Resources are squares and processes are circles. They can "arc" from one to
another. Deadlock happens when they arc in a circle.

*Deadlock Modeling slide*!!

If we have a single instance of each resouces, it *IS* possible to have
deadlock. However, if we have multiple instances, deadlock can be avoided.

## Banker's Algorithm

Uses deadlock prevention plus lsd...

"You start with a bunch of resources. You can have 10 chunks of memory for
example. Process A needs 5, B needs 4, C needs 7.... to do their job. Processes
will ask for resources and can do their job with less resouces, just at a less
efficent rate. The max that a resource can ask for is shown on the right and
the current is shown on the left. The goal is to keep everyone in a safe state;
where it is always possible to give at least one process the maximum resources
it needs. The *Banker* makes loans and the bank gives only if the bank has the
resources to give. As long as the Banker can satisy at least one resource, it
will give out what the process is asking for."

### Questions to ask

Is the state safe? "If a process can get its maximum request"

Can this process get a resource? We must check if it will be safe for everyone
else.

## Device Drivers

Handle the talking between the device and the hardware. Device drivers are
looked at in Minix as files.

IOCTL: Is often used to implement locking.

Minix requests and replys are tiny things that cannot hold much data. They are
used for contorl work or looking for a small byte message.
