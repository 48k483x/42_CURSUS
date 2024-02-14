/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:33:53 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 05:22:54 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* We handle this 5 Cases Because They are
	The only Cases
	./push_swap  2 1 3   sa
	./push_swap  3 2 1   sa | rra
	./push_swap  3 1 2   ra
	./push_swap  1 3 2   sa | ra
	./push_swap  2 3 1   rra*/

void	sort_three(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->data;
	n2 = (*a)->next->data;
	n3 = (*a)->next->next->data;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(*a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(*a);
		rra(a);
	}
	else if (n1 > n2 && n3 > n2)
		ra(a);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		sa(*a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3 && n2 > n1)
		rra(a);
}
