/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:04:58 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 08:35:59 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

int	*av_to_tab(int ac, char **av)
{
	int	i;
	int	*tab;
	int	j;
	int	k;
	int	l;

	k = 0;
	l = 0;
	if (!is_valid_integer(ac, av, &i, &j))
		exit_with_message("Error\n");
	tab = malloc(sizeof(int *) * (ac));
	if (!tab)
		return (NULL);
	while (k < ac)
	{
		tab[l] = ft_atol(av[k]);
		k++;
		l++;
	}
	return (tab);
}

void	fill_stack(t_stack **a, int ac, char **av)
{
	int		i;
	int		*tab;
	t_stack	*new_node;

	i = ac - 1;
	tab = av_to_tab(ac, av);
	input_check(ac, tab, a, av);
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_stack));
		if (NULL == new_node)
			exit(1);
		new_node->data = ft_atol(av[i]);
		new_node->next = *a;
		*a = new_node;
		i--;
	}
	free(tab);
}
