# HiPerGator Presentation

# Computer

21,000 cores in 2013 (16,000 added), but it increased and is now 50,000 cores
in 2016. 114th fastest in world.

## OS

 - RedHat linux
 - Unlike Google and Amazon that use web services with only a few nodes working
   at a time and is loosely coupled, HiPerGator has this and a strong scheduler
   to schedule the nodes. HiPerGator has to have the nodes talk
   (interconnected).

## Scheduler

Easy when each job only wants one CPU, but some jobs can take up to a week to
complete.

Automation configuration using Foreman and Puppet that helps specify the
configuration of a particular node.

Scheduling happens on a per core basis. Uses a big table to allocate cores to a
job. Keeps track of what process has control of what.

Used to run MOAB scheduler but now run Slurm. Used to run simple "batch" jobs
but now since people want to run VM's and time sensitive jobs, the scheduler
needs to maintain knowledge of busy cores. The large system allows several
thousand cores to remain idle so everyone is happy. This also allows for more
simple scheduling that is easy to understand.
