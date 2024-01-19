/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:39:31 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/19 04:10:47 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	openf_check(t_data *pipex, char *f1, char *f2)
{
	pipex->fd2 = open(f2, O_WRONLY | O_CREAT | O_TRUNC, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (pipex->fd2 < 0)
		exiti("Error In Open File For Writing\n");
	pipex->fd1 = open(f1, O_RDONLY);
	if (pipex->fd1 < 0)
		exiti("Error In Open File For Reading\n");
	if (access(f1, R_OK) < 0)
		exiti("Error Reading File\n");
	if (access(f2, W_OK) < 0)
		exiti("Error Writing File\n");
}

void	child_p(t_data *pipex, int ac, char *output_file)
{
	if (ft_strcmp(pipex->infile, "here_doc") != 0)
		dup2(pipex->fd1, 0);
	else if (ft_strcmp(pipex->infile, "here_doc") == 0)
	{
		pipex->fd_hd = open("here_doc", O_RDONLY);
		if (pipex->fd_hd < 0)
			exiti("Error In Open File For Reading\n");
		dup2 (pipex->fd_hd, 0);
	}
	if (pipex->i != ac - 2)
		dup2(pipex->fd[1], 1);
	else
	{
		pipex->fd2 = open(output_file, O_TRUNC | O_CREAT | \
				O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (pipex->fd2 < 0)
			exiti("Error In Open File For Writing\n");
		dup2(pipex->fd2, 1);
		close(pipex->fd2);
	}
	close(pipex->fd[0]);
	execve(pipex->path, pipex->cmd, NULL);
	exit(EXIT_FAILURE);
}

void	parent_p(t_data *pipex)
{
	close(pipex->fd[1]);
	pipex->fd1 = pipex->fd[0];
}

void	check_path(t_data *pipex, char *p1)
{
	if (p1 == NULL)
		exiti("Error In Command\n");
	pipex->j = 0;
	if (access(p1, X_OK) == 0)
		pipex->path = p1;
	else
	{
		pipex->env_path = getenv("PATH");
		pipex->pathh = ft_split(pipex->env_path, ':');
		while (pipex->pathh[pipex->j])
		{
			pipex->potential_path = str_concat(pipex->pathh[pipex->j], "/");
			pipex->potential_path = str_concat(pipex->potential_path, p1);
			if (access(pipex->potential_path, X_OK) == 0)
			{
				pipex->path = pipex->potential_path;
				break ;
			}
			pipex->j++;
			free(pipex->potential_path);
		}
		freex(pipex);
		if (pipex->path == NULL)
			exiti("Error In Path\n");
	}
}

int	main(int ac, char **av)
{
	t_data	pipex;

	pipex.i = 2;
	pipex.infile = NULL;
	check_heredoc(&pipex, av, ac);
	while (pipex.i < ac - 1)
	{
		pipex.cmd = ft_split(av[pipex.i], ' ');
		check_path(&pipex, pipex.cmd[0]);
		if (pipe(pipex.fd) < 0)
			exiti("Pipe Error\n");
		pipex.pid = fork();
		if (pipex.pid < 0)
			exiti("Fork Error\n");
		else if (pipex.pid == 0)
			child_p(&pipex, ac, av[ac - 1]);
		else
			parent_p(&pipex);
		pipex.i++;
	}
}
