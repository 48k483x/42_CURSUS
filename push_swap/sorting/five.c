/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:58:40 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 05:20:16 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->next->data)
	{
		sa(*a);
		pb(a, b);
	}
	else if (min->data == (*a)->next->next->data)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (min->data == (*a)->next->next->next->data)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (min->data == (*a)->next->next->next->next->data)
	{
		rra(a);
		pb(a, b);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->data)
		pb(a, b);
	else if (min->data == (*a)->next->data)
	{
		sa(*a);
		pb(a, b);
	}
	else if (min->data == (*a)->next->next->data)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (min->data == (*a)->next->next->next->data)
	{
		rra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->data)
		pb(a, b);
	else
		min_to_b(a, b);
	sort_four(a, b);
	pa(a, b);
}
