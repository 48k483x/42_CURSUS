/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:45:53 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/18 20:46:20 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*a) >= 2)
	{
		data = pop(a);
		to_bottom = create_node(data);
		tmp = stack_bottom(*a);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
	}
}

void	_rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*to_bottom;
	int		data;

	if (stack_size(*b) >= 2)
	{
		data = pop(b);
		to_bottom = create_node(data);
		tmp = stack_bottom(*b);
		to_bottom->next = tmp;
		tmp->prev = to_bottom;
	}
}

void	_rr(t_stack **a, t_stack **b)
{
	_ra(a);
	_rb(b);
}

void	_rra(t_stack **a)
{
	t_stack	*bottom;

	if (stack_size(*a) >= 2)
	{
		bottom = stack_bottom(*a);
		bottom->next->prev = NULL;
		(*a)->next = bottom;
		bottom->prev = *a;
		*a = (*a)->next;
		(*a)->next = NULL;
	}
}

void	_rrb(t_stack **b)
{
	t_stack	*bottom;

	if (stack_size(*b) >= 2)
	{
		bottom = stack_bottom(*b);
		bottom->next->prev = NULL;
		(*b)->next = bottom;
		bottom->prev = *b;
		*b = (*b)->next;
		(*b)->next = NULL;
	}
}
