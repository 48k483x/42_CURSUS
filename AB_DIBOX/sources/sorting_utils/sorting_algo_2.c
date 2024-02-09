/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:42:34 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/20 01:12:29 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_range(t_stack *a)
{
	int	range;

	range = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		range = 3;
	else if (stack_size(a) <= 100)
		range = 13;
	else if (stack_size(a) <= 500)
		range = 35;
	else
		range = 45;
	return (range);
}

static void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b);
	rb(b);
	(*i)++;
}

void	sort_others(t_stack **a, t_stack **b, int range, int size)
{
	int	*sarr;
	int	i;

	sarr = stack_to_sarray(*a);
	i = 0;
	while (*a)
	{
		if (range + i >= size)
			range = size - i - 1;
		if (stack_top(*a)->value <= sarr[i])
			pb_rb(a, b, &i);
		else if ((*a)->value > sarr[i] && (*a)->value <= sarr[range + i])
		{
			pb(a, b);
			if (stack_size(*b) >= 2 && (*b)->value < (*b)->prev->value)
				sb(b);
			i++;
		}
		else
			ra(a);
	}
	free(sarr);
}

int	max_index(t_stack *b)
{
	int	index;

	index = 0;
	while (b && stack_max(b) != b)
	{
		b = b->prev;
		index++;
	}
	return (index);
}

void	max_to_top(t_stack **b)
{
	int	index;
	int	size;

	size = stack_size(*b);
	while (1)
	{
		index = max_index(*b);
		if (index == 0)
			break ;
		else if (index <= size / 2)
			rb(b);
		else if (index > size / 2)
			rrb(b);
	}
}
