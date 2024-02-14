/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:48:49 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 03:50:05 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(stack *a)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(stack *b)
{
	int	tmp;

	if (b && b->next)
	{
		tmp = b->data;
		b->data = b->next->data;
		b->next->data = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(stack *a, stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
