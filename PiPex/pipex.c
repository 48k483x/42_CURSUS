#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;

    pipe(fd);
    pid = fork();

    if (pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        char *cmd1[] = { "ls", NULL };
        execvp(cmd1[0], cmd1);
    }
    else
    {
        wait(NULL);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        char *cmd2[] = { "wc", "-l", NULL };
        execvp(cmd2[0], cmd2);
    }

    return 0;
}
