/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:53:54 by aboudiba          #+#    #+#             */
/*   Updated: 2024/02/09 04:53:36 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(int a, int b)
{
	return (a < b);
}

int	stack_sorted(t_stack *s, int (*sorted)(int, int))
{
	t_stack	*tmp;

	tmp = s;
	while (tmp->prev)
	{
		if (sorted(tmp->value, tmp->prev->value) == 0)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

t_stack	*stack_bottom(t_stack *s)
{
	t_stack	*tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

void	initialize_stack(t_stack **a, int ac, char **av)
{
	int		j;
	char	**sp;

	while (ac >= 0)
	{
		sp = ft_split(av[ac], ' ');
		if (sp == NULL)
		{
			free(sp);
			error_generator();
		}
		j = 0;
		while (sp[j + 1])
			j++;
		while (j >= 0)
		{
			if (av_error(sp[j]) || dup_error(*a, ft_atol(sp[j])))
				error_generator();
			push(a, ft_atol(sp[j]));
			j--;
		}
		j = 0;
		free_all(sp);
		ac--;
	}
    // printf("%d\n", (*a)->value);
    // printf("%d\n", (*a)->prev->value);	
	// printf("%d\n", (*a)->prev->value);
	// printf("%d\n", (*a)->prev->value);
	// printf("%d\n", (*a)->prev->value);
    	
}
