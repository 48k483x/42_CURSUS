/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:35:15 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/15 03:35:41 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_with_message(char *s)
{
	while (*s)
		write(2, s++, 1);
	exit(1);
}

void	free_all(t_stack *a, char **arr)
{
	free_split(arr);
	free_stack(&a);
}

bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	arr_n(char **arr, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && is_space(av[i][j]))
			j++;
		if (av[i][j] == '\0')
		{
			free_split(arr);
			exit_with_message("Error\n");
		}
		i++;
	}
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
