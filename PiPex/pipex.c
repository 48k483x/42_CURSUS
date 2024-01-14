#include "pipex.h"

void    openf_check(t_data *pipex, char *f1, char *f2)
{
    if ((pipex->fd2 = open(f2, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
        exiti("Error In Open File For Writing\n");
    if ((pipex->fd1 = open(f1, O_RDONLY)) < 0)
        exiti("Error In Open File For Reading\n");
    if (access(f1, R_OK) < 0)
        exiti("Error Reading File\n");
    if (access(f2, W_OK) < 0)
        exiti("Error Writing File\n");
}

int main(int ac, char **av)
{
    t_data pipex;
    if (ac != 5)
        exiti("Incorrect Args Num\n");
    openf_check(&pipex, av[1], av[4]);
    pipex.cmd1 = ft_split(av[2], ' ');   // must be freed
    pipex.cmd2 = ft_split(av[3], ' ');  // must be freed
    pipex.path = str_concat("/bin/", pipex.cmd1[0]); // must be freed
    pipex.spath = str_concat("/bin/",pipex.cmd2[0]);// must be freed
    if (pipe(pipex.fd) < 0)
        exiti("Pipe Error\n");
    if ((pipex.pid = fork()) < 0)
        exiti("Fork Error\n");
    else if (pipex.pid == 0)
    {
        dup2(pipex.fd1, STDIN_FILENO);
        close(pipex.fd1);
        dup2(pipex.fd[1], STDOUT_FILENO);  // 1
        close(pipex.fd[0]);
        execve(pipex.path, pipex.cmd1, NULL);
    }
    else
    {
        wait(NULL);
        dup2(pipex.fd2, STDOUT_FILENO);
        close(pipex.fd2);
        dup2(pipex.fd[0], STDIN_FILENO);  // 0
        close(pipex.fd[1]);
        execve(pipex.spath, pipex.cmd2, NULL);
    }
}
