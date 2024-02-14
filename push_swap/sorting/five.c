/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:58:40 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 04:02:48 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_b(stack **a, stack **b)
{
	stack	*min;

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

void	sort_four(stack **a, stack **b)
{
	stack	*min;

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

void	sort_five(stack **a, stack **b)
{
	stack	*min;

	min = stack_smallest(a);
	if (min->data == (*a)->data)
		pb(a, b);
	else
		min_to_b(a, b);
	sort_four(a, b);
	pa(a, b);
}
