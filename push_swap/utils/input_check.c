/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:48:10 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/15 03:48:11 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	integer_check(int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_integer(int ac, char **av, t_index *index)
{
	index->i = 0;
	while (index->i < ac)
	{
		if (av[index->i] == NULL)
			return (false);
		index->j = 0;
		while (av[index->i][index->j] != '\0' && (av[index->i][index->j] == ' '
			|| (av[index->i][index->j] >= 9 && av[index->i][index->j] <= 13)))
			index->j++;
		if (av[index->i][index->j] == '+' || av[index->i][index->j] == '-')
		{
			index->j++;
			if (av[index->i][index->j] == '\0')
				return (false);
		}
		while (av[index->i][index->j] != '\0')
		{
			if (!ft_isdigit(av[index->i][index->j]))
				return (false);
			index->j++;
		}
		index->i++;
	}
	return (true);
}

bool	double_check(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (tab[i] == tab[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_sorted(int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (i == ac - 1)
			break ;
		else if (tab[i] > tab[i + 1] || tab[i] == tab[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	input_check(int ac, int *tab, char **av)
{
	if (is_sorted(tab, ac))
	{
		free(tab);
		free_split(av);
		exit(0);
	}
	if (!integer_check(tab, ac))
	{
		free(tab);
		free_split(av);
		exit_with_message("Error\n");
	}
	if (!double_check(tab, ac))
	{
		free(tab);
		free_split(av);
		exit_with_message("Error\n");
	}
	if (ac < 2)
	{
		free(tab);
		free_split(av);
		exit(0);
	}
	return (true);
}
