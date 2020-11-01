
#include "types.h"
#include "user.h"

int number_of_processes = 5;
long long inf = 1e9 / 5;

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
    else if (pid == 0)
    {
      for (volatile int k = 0; k < inf; k++)
      {
        ;
      }
      printf(1, "Process:%d %d Finished\n", j, getpid());
      exit();
    }
    else
    {
      ;
      set_priority(80 + (j % 3), pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  // for (j = 0; j < number_of_processes+5; j++)
  // {
  //   wait();
  // }
  exit();
}
