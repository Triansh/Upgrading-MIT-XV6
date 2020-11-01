#include "types.h"
#include "user.h"

int number_of_processes = 5;

int main(int argc, char *argv[])
{
  int j;
  // set_priority(10, getpid());
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
        // if (k <= j)
        // {
        //   // sleep(20); //io time
        // }
        // else
        // {
          for (i = 0; i < (int)1e8; i++)
          {
            ; //cpu time
          }
        // }
      }
      // printf(1, "Process: %d Finished pid: %d\n", j, getpid());
      exit();
    }
    else
    {
      ;
      // set_priority(80+j%3, pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  for (j = 0; j < number_of_processes; j++)
  {
    wait();
  }
  exit();
}