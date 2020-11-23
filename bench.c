#include "types.h"
#include "user.h"

int number_of_processes = 17;

int main(int argc, char *argv[])
{
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      volatile int i;
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(200); //io time
        }
        else
        {
          for (i = 0; i < 100000000; i++)
          {
            ; //cpu time
          }
        }
      }
    //   printf(1, "Process: %d Finished\n", j);
      exit();
    }
    else{
        
     set_priority(100-(40+j),pid);
     ps();
     printf(1,"\n\n\n");
      // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  for (j = 0; j < number_of_processes; j++)
  {
    /*int *wtime;
    int *rtime;
    int pid;
    wtime = (int *) malloc(sizeof(int));
    rtime = (int *) malloc(sizeof(int));
    pid = 0;
    pid += 1;
    pid = waitx(wtime,rtime);
    printf(1,"%d: ",pid);
    printf(1,"waiting time is %d: ",*wtime);
    printf(1,"total running time is %d: \n",*rtime);
    printf(1,"sfsfsf");*/
  }
  exit();
}