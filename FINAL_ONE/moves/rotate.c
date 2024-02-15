/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:45:51 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 16:28:13 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ra(t_stack **a, int param)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	if (!param)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int param)
{
	t_stack	*last;
	t_stack	*current;

	if (!(*b) || !(*b)->next)
		return ;
	last = (*b);
	*b = (*b)->next;
	current = (*b);
	while (current->next)
		current = current->next;
	current->next = last;
	last->next = NULL;
	if (!param)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int param)
{
	ra(a, 0);
	rb(b, 0);
	if (param)
		write(1, "rr\n", 3);
}
