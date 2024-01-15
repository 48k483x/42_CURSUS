/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:39:31 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/14 15:03:56 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void openf_check(t_data *pipex, char *f1, char *f2)
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

void    child_p(t_data *pipex)
{
    if (dup2(pipex->fd1, STDIN_FILENO) < 0)
    {
        exiti("Dup2 Error\n");
    }
	close(pipex->fd1);
	if (dup2(pipex->fd[1], STDOUT_FILENO) < 0)
    {
        exiti("Dup2 Error\n");
    }
	close(pipex->fd[0]);
    if (execve(pipex->path, pipex->cmd1, NULL) < 0)
    {
        exiti("Execve Error\n");
    }
}

void    parent_p(t_data *pipex)
{
    wait(NULL);
	if (dup2(pipex->fd2, STDOUT_FILENO) < 0)
    {
        exiti("Dup2 Error\n");
    }
	close(pipex->fd2);
	if (dup2(pipex->fd[0], STDIN_FILENO) < 0)
    {
        exiti("Dup2 Error\n");
    }
	close(pipex->fd[1]);
	if (execve(pipex->spath, pipex->cmd2, NULL) < 0)
    {
        exiti("Execve Error\n");
    }
}

int main(int ac, char **av)
{
	t_data pipex;
	if (ac != 5)
		exiti("Incorrect Args Num\n");
	openf_check(&pipex, av[1], av[4]);
	pipex.cmd1 = ft_split(av[2], ' ');					  // must be freed
	pipex.cmd2 = ft_split(av[3], ' ');					  // must be freed
	pipex.path = str_concat("/bin/", pipex.cmd1[0]);  // must be freed
	pipex.spath = str_concat("/bin/", pipex.cmd2[0]); // must be freed
	if (pipe(pipex.fd) < 0)
		exiti("Pipe Error\n");
	if ((pipex.pid = fork()) < 0)
		exiti("Fork Error\n");
	else if (pipex.pid == 0)
        child_p(&pipex);
	else
        parent_p(&pipex);
}
