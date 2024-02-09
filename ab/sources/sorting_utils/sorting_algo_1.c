/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:42:54 by aboudiba          #+#    #+#             */
/*   Updated: 2024/02/09 05:52:48 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	start_sort(t_stack **a, t_stack **b)
{
	(void)b;
	if (stack_size(*a) == 2)
		sa(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 4)
		sort_four(a, b);
	else if (stack_size(*a) == 5)
	{
		 
		sort_five(a, b);
	// 	printf("%d\n", (*a)->value);
    // printf("%d\n", (*a)->prev->value);	
	// printf("%d\n", (*a)->prev->value);
	// printf("%d\n", (*a)->prev->value);
	// printf("%d\n", (*a)->prev->value);
	}
	else if (stack_size(*a) >= 6)
	{
		sort_others(a, b, get_range(*a), stack_size(*a));
		while (*b)
		{
			max_to_top(b);
			pa(a, b);
		}
	}
}

// void	sort_three(t_stack **a)
// {
// 	if (stack_top(*a)->value > stack_top(*a)->prev->value
// 		&& stack_top(*a)->prev->value > stack_bottom(*a)->value)
// 	{
// 		ra(a);
// 		sa(a);
// 	}
// 	else if (stack_top(*a)->value > stack_top(*a)->prev->value
// 		&& stack_bottom(*a)->value > stack_top(*a)->prev->value
// 		&& stack_top(*a)->value > stack_bottom(*a)->value)
// 		ra(a);
// 	else if (stack_top(*a)->value < stack_bottom(*a)->value
// 		&& stack_top(*a)->value < stack_top(*a)->prev->value
// 		&& stack_top(*a)->prev->value > stack_bottom(*a)->value)
// 	{
// 		sa(a);
// 		ra(a);
// 	}
// 	else if (stack_top(*a)->value < stack_top(*a)->prev->value
// 		&& stack_bottom(*a)->value < stack_top(*a)->value
// 		&& stack_top(*a)->prev->value > stack_bottom(*a)->value)
// 		rra(a);
// 	else
// 		sa(a);
// }

void	sort_three(t_stack **a)
{
	if (stack_top(*a)->value > stack_top(*a)->prev->value
		&& stack_top(*a)->prev->value > stack_bottom(*a)->value)
	{
		ra(a);
		sa(a);
	}
	else if (stack_top(*a)->value > stack_top(*a)->prev->value
		&& stack_bottom(*a)->value > stack_top(*a)->prev->value
		&& stack_top(*a)->value > stack_bottom(*a)->value)
		ra(a);
	else if (stack_top(*a)->value < stack_bottom(*a)->value
		&& stack_top(*a)->value < stack_top(*a)->prev->value
		&& stack_top(*a)->prev->value > stack_bottom(*a)->value)
	{
		sa(a);
		ra(a);
	}
	else if (stack_top(*a)->value < stack_top(*a)->prev->value
		&& stack_bottom(*a)->value < stack_top(*a)->value
		&& stack_top(*a)->prev->value > stack_bottom(*a)->value)
		rra(a);
	else if (stack_top(*a)->value > stack_top(*a)->prev->value
		&& stack_bottom(*a)->value > stack_top(*a)->value)
		sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (stack_min(*a) == stack_bottom(*a))
		rra(a);
	else if (stack_min(*a) == stack_bottom(*a)->next)
	{
		rra(a);
		rra(a);
	}
	else if (stack_min(*a) == stack_top(*a)->prev)
		sa(a);
	if (!stack_sorted(*a, sorted))
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
}

void	min_to_b(t_stack **a, t_stack **b)
{
	if (stack_min(*a) == stack_top(*a))
		pb(a, b);
	else if (stack_min(*a) == stack_top(*a)->prev)
	{
		sa(a);
		pb(a, b);
	}
	else if (stack_min(*a) == stack_bottom(*a)->next)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (stack_min(*a) == stack_bottom(*a))
	{
		rra(a);
		pb(a, b);
	}
	else
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
}

// void	sort_five(t_stack **a, t_stack **b)
// {
// 	min_to_b(a, b);
// 	min_to_b(a, b);
// 	sort_three(a);
// 	pa(a, b);
// 	pa(a, b);
// }
void	sort_five(t_stack **a, t_stack **b)
{
	min_to_b(a, b);
	min_to_b(a, b);
	sort_three(a);
	if ((*b)->value < (*b)->prev->value)
		sb(b);
	pa(a, b);
	if ((*a)->value < (*a)->prev->value)
		sa(a);
	pa(a, b);
	if ((*a)->value < (*a)->prev->value)
		sa(a);
}