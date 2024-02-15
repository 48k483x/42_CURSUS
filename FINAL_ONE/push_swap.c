/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:24:38 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 20:36:30 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		arr_num;
	char	**arr;

	b = NULL;
	a = NULL;
	arr = _parsed_arr(_parsed_av(ac, av));
	arr_num = arr_n(arr, av);
	fill_stack(&a, arr_num, arr);
	if (arr_num == 2 && a->data > a->next->data)
		sa(a, 0);
	else if (arr_num == 3)
		sort_three(&a);
	else if (arr_num == 4)
		sort_four(&a, &b);
	else if (arr_num == 5)
		sort_five(&a, &b);
	else
	{
		quick_divide_qs(&a, &b, find_interval(&a), stack_size(&a));
		while (b)
			move_max_up(&a, &b);
	}
	free_all(a, arr);
}
