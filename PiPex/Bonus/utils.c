/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:40:16 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/16 15:10:18 by achahrou         ###   ########.fr       */
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
