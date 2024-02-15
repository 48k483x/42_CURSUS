/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:36:44 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:47 by abkabex          ###   ########.fr       */
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
	int		i;
	int		*tab;
	int		j;
	t_index	*index;

	index = malloc(sizeof(t_index));
	if (!index)
		return (NULL);
	i = 0;
	j = 0;
	index->i = 0;
	index->j = 0;
	if (!length_check(av) || !is_valid_integer(ac, av, index))
		exit_with_message("Error\n");
	tab = malloc(sizeof(int *) * (ac));
	if (!tab)
		return (NULL);
	while (i < ac)
	{
		tab[j] = ft_atol(av[i]);
		i++;
		j++;
	}
	free(index);
	return (tab);
}

void	fill_stack(t_stack **a, int ac, char **av)
{
	int		i;
	int		*tab;
	t_stack	*new_node;

	i = ac - 1;
	tab = av_to_tab(ac, av);
	input_check(ac, tab, av);
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
