#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf(2, "setPriority: Too less arguments.\n");
        printf(2, "Provide command in the form setPriority new_priority pid.\n");
        exit();
    }

    int new_priority = atoi(argv[1]);
    int pid = atoi(argv[2]);
    int ret = set_priority(new_priority, pid);
    if(ret < 0){
        printf(2, "setPriority: Error in changing priority");
    }

    exit();
}