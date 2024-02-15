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

int	_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	fill_stack(&a, arr_num, arr);
	if (!sorted(&a))
	{
		start_checking(&a, &b);
		if (sorted(&a) == 1 && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}
