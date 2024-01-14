#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int 
main()
{
    char *cmd[] = {"ls", NULL};
    //fork();
    printf("It's Me Achahrou -> PID -> %d\n", getpid());
    fflush(stdout);
    execvp(cmd[0], cmd);
}
