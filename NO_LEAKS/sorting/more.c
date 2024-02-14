/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:12:44 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 08:25:58 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_interval(t_stack **a)
{
	int	interval;

	interval = 0;
	if (stack_size(a) >= 6 && stack_size(a) <= 16)
		interval = 3;
	else if (stack_size(a) <= 100)
		interval = 13;
	else if (stack_size(a) <= 500)
		interval = 30;
	else
		interval = 45;
	return (interval);
}

void	pb_rb(t_stack **a, t_stack **b, int *i)
{
	pb(a, b);
	rb(b);
	(*i)++;
}

void	quick_divide_qs(t_stack **a, t_stack **b, int interval, int size)
{
	int	i;
	int	*s_arr;

	i = 0;
	s_arr = sorted_stack_array(a);
	while (*a)
	{
		if (interval + i >= size)
			interval = size - i - 1;
		if (stack_head(a)->data <= s_arr[i])
			pb_rb(a, b, &i);
		else if ((*a)->data > s_arr[i] && (*a)->data <= s_arr[i + interval])
		{
			pb(a, b);
			if (stack_size(b) >= 2 && (*b)->data < (*b)->next->data)
				sb(*b);
			i++;
		}
		else
			ra(a);
	}
	free(s_arr);
}

void	move_max_up(t_stack **b)
{
	int	size;
	int	peak;

	size = stack_size(b);
	peak = 0;
	while (1)
	{
		peak = peak_index(b, stack_biggest(b));
		if (peak == 0)
			break ;
		else if (peak <= size / 2)
			rb(b);
		else if (peak > size / 2)
			rrb(b);
	}
}
