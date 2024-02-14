#include "../push_swap.h"

stack	*ft_lstnew(int content)
{
	stack	*new_node;

	new_node = (stack *)malloc(sizeof(stack));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

int *av_to_tab(int ac, char **av)
{
    int i;
    int *tab;
    int j;

    i = 0;
    j = 0;
    if (!is_valid_integer(ac, av))
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
    return (tab);
}

// void    fill_stack(stack **a, int ac, char **av)
// {
//     int *tab;
//     int i;

//     tab = av_to_tab(ac, av);
//     input_check(ac, tab);
//     i = ac;
//     while (i > 0)
//     {
//         ft_lstadd_front(a, ft_lstnew(tab[i]));
//         i--;
//     }
// }
void fill_stack(stack **a, int ac, char **av)
{
    int i = ac - 1;

    int *tab = av_to_tab(ac, av);
    input_check(ac, tab, a, av);
    while (i >= 0)
    {
        stack *new_node = malloc(sizeof(stack));
        if (NULL == new_node)
            exit(1);
        new_node->data = ft_atol(av[i]);
        new_node->next = *a;
        *a = new_node;
        i--;
    }
    free(tab);
}
    