System Call Waitx
    added waitx to proc.c
    changes done in Makefile, defs.h, user.h, usys.S, syscall.c, syscall.h, sysproc.c, trap.c

Schedulers
    Running a infnite loop to run scheduler
    FCFS
        Iterated through the ptable to find the process which has least ctime and executed it.
        ctime is assigned when fork is called.
    PBS
        Finding the least priority process and running it.
        Iterating through the table to run processes which have least priotrity and running them as RR manner.
        priority can be changed through setPriority command.
    MLFQ
        created five queues to store process. These queues store only Runnable process.
        There are two function to add proccess and remove process from queues.
        When a process is created it will be added to q0.
        Aging is done through iterating through all queues and checking a process how much time it is in that queue. If it has exceeded the limit , it will be removed and added to upper queue.
        If top queues has processes I will run those first. i.e, the process which is first from the top is going to be executed.
        If a procces runs more than the time slice of current queue, then it is removed and added to lower queue. If it is last queue, it will stay there.