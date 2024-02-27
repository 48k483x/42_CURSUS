/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:46:59 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/15 05:10:27 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a, int param)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
		if (!param)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b, int param)
{
	int	tmp;

	if (b && b->next)
	{
		tmp = b->data;
		b->data = b->next->data;
		b->next->data = tmp;
		if (!param)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b, int param)
{
	sa(a, 1);
	sb(b, 1);
	if (!param)
		write(1, "ss\n", 3);
}
