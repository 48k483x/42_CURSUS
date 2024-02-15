/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 03:36:32 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/15 03:41:20 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	apply_operations(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", _strlen(line)) == 0)
		sa(*a, 1);
	else if (ft_strncmp(line, "sb\n", _strlen(line)) == 0)
		sb(*b, 1);
	else if (ft_strncmp(line, "ss\n", _strlen(line)) == 0)
		ss(*a, *b, 1);
	else if (ft_strncmp(line, "pa\n", _strlen(line)) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(line, "pb\n", _strlen(line)) == 0)
		pb(a, b, 1);
	else if (ft_strncmp(line, "ra\n", _strlen(line)) == 0)
		ra(a, 1);
	else if (ft_strncmp(line, "rb\n", _strlen(line)) == 0)
		rb(b, 1);
	else if (ft_strncmp(line, "rr\n", _strlen(line)) == 0)
		rr(a, b, 1);
	else if (ft_strncmp(line, "rra\n", _strlen(line)) == 0)
		rra(a, 1);
	else if (ft_strncmp(line, "rrb\n", _strlen(line)) == 0)
		rrb(b, 1);
	else if (ft_strncmp(line, "rrr\n", _strlen(line)) == 0)
		rrr(a, b, 1);
	else
		exit_with_message("Error\n");
}

void	start_checking(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_operations(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

void	bonus_fill_stack(t_stack **a, int ac, char **av)
{
	int		i;
	int		*tab;
	t_stack	*new_node;

	i = ac - 1;
	tab = av_to_tab(ac, av);
	if (!integer_check(tab, ac) || !double_check(tab, ac))
	{
		free(tab);
		free_split(av);
		exit_with_message("Error\n");
	}
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		arr_num;
	char	**arr;

	b = NULL;
	a = NULL;
	arr = _parsed_arr(_parsed_av(ac, av));
	arr_num = arr_n(arr, av);
	bonus_fill_stack(&a, arr_num, arr);
	start_checking(&a, &b);
	if (sorted(&a) == 1 && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}
