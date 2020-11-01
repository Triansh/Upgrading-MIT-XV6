#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf(2, "time: Too less arguments. Expecting atleast one argument.\n");
        exit();
    }

    int pid = fork();

    if (pid < 0)
    {
        printf(2, "time: Error in creating process.\n");
        exit();
    }
    else if (pid == 0)
    {
        int ret = exec(argv[1], argv + 1);
        if (ret < 0)
        {
            printf(2, "exec: Error in running command.\n");
            exit();
        }
    }
    else
    {
        int wtime, rtime;
        waitx(&wtime, &rtime);
        printf(1, "Time Report:\n");
        printf(1, "PID: %d\n Runtime: %d\n Wait-time: %d\n", , pid, rtime, wtime);

    }
    exit();
}