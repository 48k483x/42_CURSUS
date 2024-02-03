#include "../push_swap.h"

stack	*ft_lstnew(int content)
{
	stack	*new_node;

	new_node = (stack *)malloc(sizeof(stack));
	if (!new_node)
		exit_with_message("Error\n");
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

int *av_to_tab(int ac, char **av)
{
    int i;
    int *tab;
    int j;

    i = 1;
    j = 0;
    if (!is_valid_integer(ac, av))
        exit_with_message("Error\n");
    tab = (int *)malloc(sizeof(int) * (ac - 1));
    if (!tab)
        exit_with_message("Error\n");
    while (i < ac)
    {
        tab[j] = ft_atoi(av[i]);
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
    input_check(ac, tab, a);
    while (i > 0)
    {
        stack *new_node = malloc(sizeof(stack));
        if (new_node == NULL)
            exit_with_message("Error In Allocation\n");

        new_node->data = atoi(av[i]);
        new_node->next = *a;
        *a = new_node;

        i--;
    }
    free(tab);
}
    