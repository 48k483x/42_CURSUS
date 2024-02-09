/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:22:57 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/18 20:23:01 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	_sa(t_stack **a)
{
	if (stack_size(*a) >= 2)
	{
		swap(&(*a)->value, &(*a)->prev->value);
	}
}

void	_sb(t_stack **b)
{
	if (stack_size(*b) >= 2)
	{
		swap(&(*b)->value, &(*b)->prev->value);
	}
}

void	_ss(t_stack **a, t_stack **b)
{
	if (stack_size(*a) >= 2)
		swap(&(*a)->value, &(*a)->prev->value);
	if (stack_size(*b) >= 2)
		swap(&(*b)->value, &(*b)->prev->value);
}

void	_pa(t_stack **a, t_stack **b)
{
	if (stack_size(*b))
	{
		push(a, pop(b));
	}
}

void	_pb(t_stack **a, t_stack **b)
{
	if (stack_size(*a))
	{
		push(b, pop(a));
	}
}
