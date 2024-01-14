#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    pid_t pid;
    int fd[2];

    if (ac < 3) // assuming you only want to pipe between two commands
    {
        printf("Usage: %s cmd1 cmd2\n", av[0]);
        return 1;
    }

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        if (execvp(av[1], av + 1) == -1)
        {
            perror("execvp child");
            exit(1);
        }
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        if (wait(NULL) == -1)
        {
            perror("wait");
            return 1;
        }

        if (execvp(av[2], av + 2) == -1)
        {
            perror("execvp parent");
            exit(1);
        }
    }

    return 0;
}

