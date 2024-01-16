/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:39:31 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/16 15:21:47 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	openf_check(t_data *pipex, char *f1, char *f2)
{
	pipex->fd2 = open(f2, O_WRONLY | O_CREAT | O_TRUNC);
	if (pipex->fd2)
		exiti("Error In Open File For Writing\n");
	pipex->fd1 = open(f1, O_RDONLY);
	if (pipex->fd1)
		exiti("Error In Open File For Reading\n");
	if (access(f1, R_OK) < 0)
		exiti("Error Reading File\n");
	if (access(f2, W_OK) < 0)
		exiti("Error Writing File\n");
}

void	child_p(t_data *pipex, int ac)
{
	dup2 (pipex->fd1, 0);
	if (pipex->i != ac - 2)
		dup2(pipex->fd[1], 1);
	else
	{
		dup2(pipex->fd2, 1);
		close(pipex->fd2);
	}
	close(pipex->fd[0]);
	execve(pipex->path, pipex->cmd, NULL);
	exit(EXIT_FAILURE);
}

void	parent_p(t_data *pipex)
{
	wait(NULL);
	close(pipex->fd[1]);
	pipex->fd1 = pipex->fd[0];
}

int	main(int ac, char **av)
{
	t_data	pipex;

	pipex.i = 2;
	openf_check(&pipex, av[1], av[ac -1]);
	while (pipex.i < ac - 1)
	{
		pipex.cmd = ft_split(av[pipex.i], ' ');
		pipex.path = str_concat("/bin/", pipex.cmd[0]);
		if (pipe(pipex.fd) < 0)
			exiti("Fork Error\n");
		pipex.pid = fork();
		if (pipex.pid < 0)
			exiti("Fork Error\n");
		else if (pipex.pid == 0)
			child_p(&pipex, ac);
		else
			parent_p(&pipex);
		pipex.i++;
	}
}
