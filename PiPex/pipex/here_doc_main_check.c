#include "pipex.h"

void	check_heredoc(t_data *pipex, char **av, int ac)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		handle_heredoc(pipex, av[2]);
		pipex->i++;
	}
	else
	{
		openf_check(pipex, av[1], av[ac -1]);
		pipex->infile = av[1];
	}
}

void	handle_heredoc(t_data *pipex, char *limiter)
{
	printf("pipex->infile: %s\n", pipex->infile);
	pipex->line = NULL;
	pipex->fd_hd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_hd < 0)
		exiti("Error In Open fd_hd For Writing\n");
	pipex->line = get_next_line(0);
	while (pipex->line)
	{
		if (ft_strcmp(pipex->line, limiter) == 0)
			break ;
		write(pipex->fd_hd, pipex->line, ft_strlen(pipex->line));
		pipex->line = get_next_line(0);
	}
	close(pipex->fd_hd);
	pipex->infile = "here_doc";
}