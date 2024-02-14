/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:25:27 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 04:30:17 by achahrou         ###   ########.fr       */
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

int	*sorted_stack_array(stack **a)
{
	int		i;
	int		*s_arr;
	stack	*tmp;

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

int	stack_biggest(stack **a)
{
	stack	*tmp;
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

stack	*stack_smallest(stack **a)
{
	stack	*tmp;
	stack	*smallest;

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

int	peak_index(stack **b, int peak)
{
	stack	*tmp;
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
