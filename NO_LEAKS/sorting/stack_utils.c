/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:22:44 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 04:31:58 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	sorted(stack **a)
{
	stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

stack	*stack_head(stack **a)
{
	if (!*a || !a)
		return (NULL);
	return (*a);
}

void	print_stack(stack *s)
{
	stack	*temp;

	if (s == NULL)
		return ;
	temp = s;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		if (temp->next != NULL)
			printf(" -> ");
		temp = temp->next;
	}
	printf("\n");
}

void	free_stack(stack **a)
{
	stack	*current;
	stack	*next;

	current = *a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}

int	stack_size(stack **a)
{
	if (!a || !*a)
		return (0);
	else
		return (1 + stack_size(&(*a)->next));
}
