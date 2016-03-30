# Project 2: Semaphores

Jonathan Poisson -- Poisson.Jonathan777@gmail.com

## Overall Implementation

### Server

I decided to created support for semaphores in Minix 3.2.1. by creating a
stand-alone semaphore service. Instead of adding semaphore operations to the PM
of VFS server, I found that I had more freedom and ease of implementation by
creating a new servce to run a unique service. This service controls the
creation of semaphores, the waiting queue, and the up and down operations on
the semaphores. The service is started up automatically when the OS boots.

#### Create Semaphore

Create semaphore take the initial value and type of semaphore to create the
semaphore in the semaphore service. Internally, there is an array of semaphores
(allowing for up to 5 unique semaphores) and the create_semaphore operation is
successfull if there is an open slot in the semaphore array, allowing the slot
to be filled with the semaphore value. The return value is a semaphore handle
that represents the index in the semaphore array where the created semaphore
resides.

#### Delete Semaphore

Delete semaphore takes a semaphore handle (index in semaphore array) and has
the purpose of freeing a spot in the semaphore array (setting it back to -1).
The call is successfull and will return -1 if the semaphore handle is a valid
entry in the array and has a created semaphore in the given index. The call is
successfull and will return -1 if the semaphore handle is a valid entry in the
array and has a created semaphore in the given index.
