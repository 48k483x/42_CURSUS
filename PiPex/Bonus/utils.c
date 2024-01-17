/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:40:16 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/17 11:18:56 by achahrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exiti(char *s)
{
	perror(s);
	exit(1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_concat(char *s1, char *s2)
{
	char	*concat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	concat = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!concat)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i] = s2[j];
		j++;
		i++;
	}
	return (concat);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		while ((i + j) < len && big[i + j] == little[j] && big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}

void	handle_heredoc(t_data *pipex, char *limiter)
{
	pipex->line = NULL;
	pipex->fd_hd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_hd < 0)
		exiti("Error In Open fd_hd For Writing\n");
	while ((pipex->line = get_next_line(0)))
	{
		if (ft_strcmp(pipex->line, limiter) == 0)
		break;
		write(pipex->fd_hd, pipex->line, ft_strlen(pipex->line));
		//write(pipex->fd_hd, "\n", 1);
		//write(pipex->fd_hd, "\n", 1);
	}
	close(pipex->fd_hd);
	pipex->infile = "here_doc";
}
/*
	 We splited to the utils part
	 exiti(You Custom Error Messg);
		  function that we handle errors in
		  out pipex program, it send an mssg
		  to stdout then it exit;
	 as we know the is 8 ways for an
	 process to terminate 5 Normal are :
		  exit();
		  return ; from the main
		  _exit || _Exit
		  return of the last thread from its
								start Routine
		  calling pthread_exit from the last
									 thread.
	 then we used the ft_strlen() to use it
	 in the str_concat function.
	 cause wow among all exec functions
	 they choosed the execve that work with the
	 pathname not filename. So we need the path
	 that is stored in /bin/filename of the command
	 so to do it i did the str_concat to concat
	 the command name and it path.
 */
