/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:14:36 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/19 15:14:38 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* 
This function opens the input and output files.
checks if the files can be opened for RD and WR,
and if not, it exiti() lia mn lprogram with an 
error message.
*/
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

/* this function is for the child process, so its when 
   the pid == 0, it check first if its an here_doc, if 
   its, it will redirect the stdin (0) to the here_doc
   file, if its not, it will do the same thing with the
   fd1 of the file f1, then it check if its not the last
   cmd, then it duplicate the stdout to the RD fd of the 
   pipe, if it's the last, then we redirect stdout to the
   output file, then we close the RD fd of the pipe, then
   we call execve to execute the cmd, if there is an error 
   with the command it will just exit */
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
/* i close the write end of the pipe, then i redirect
the input to the read end of the pipe for the next command
so the input of the next cmd will be fd1, that is 
the read end of the pipe , cause we alrady did in our code 
if its not the last redirect the stdout to fd[1] that is the 
write end of the pip */

void	parent_p(t_data *pipex)
{
	close(pipex->fd[1]);
	pipex->fd1 = pipex->fd[0];
}

/* its just an function to check path for the command,
   we get the env variable using getenv();
   getenv("PATH") is used to get the value of the PATH 
   environment variable. The PATH environment variable 
   is a list of directories where the system looks for 
   executables when a command is run. then we strat checking
   if its it the right path of the command then store it*/
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

/* The main function, where everything start hahaha */
int	main(int ac, char **av)
{
	t_data	pipex;

	pipex.i = 2;
	pipex.infile = NULL;
    if (ac < 5)
    {
        exiti("ac is < than 4\n");
    }
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
