#include <stdio.h> // printf() function
#include <unistd.h> // pipe(), fork(), dup2(), execlp()
#include <sys/types.h> // pid_t type
#include <sys/wait.h> // wait() function
#include <stdlib.h> // execvp() function

int main(int ac, char **av)
{
    pid_t pid;
    int fd[2];
    char *cmd1[] = {av[1], NULL};
    char *cmd2[] = {av[3], av[4], NULL};

    if (ac < 4)
    {
        printf("usage: pip cmd1 cmd2\n");
        return (1);
    }
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        dup2(fd[1], 1); // redirect stdout to pipe
        close(fd[0]);  // close read end
        execve(cmd1[0], cmd1, NULL); // execute command
    }
    else if (pid > 0)
    {
        wait(NULL); // wait for child to finish
        dup2(fd[0], 0); // redirect stdin to pipe
        close(fd[1]);   // close write end
        execve(cmd2[0], cmd2, NULL); // execute command
    }
    else
    {
        printf("fork error , /n");
        return 1;
    }
}
