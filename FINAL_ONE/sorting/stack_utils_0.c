/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:25:27 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 05:22:01 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_int_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_stack_array(t_stack **a)
{
	int		i;
	int		*s_arr;
	t_stack	*tmp;

	s_arr = malloc(sizeof(int *) * stack_size(a));
	if (!s_arr)
		return (NULL);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		s_arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sort_int_array(s_arr, stack_size(a));
	return (s_arr);
}

int	stack_biggest(t_stack **a)
{
	t_stack	*tmp;
	int		biggest;

	tmp = *a;
	biggest = tmp->data;
	while (tmp)
	{
		if (tmp->data > biggest)
			biggest = tmp->data;
		tmp = tmp->next;
	}
	return (biggest);
}

t_stack	*stack_smallest(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*smallest;

	tmp = *a;
	smallest = tmp;
	while (tmp)
	{
		if (tmp->data < smallest->data)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

int	peak_index(t_stack **b, int peak)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == peak)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
