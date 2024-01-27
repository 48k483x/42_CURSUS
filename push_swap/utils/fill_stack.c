#include "../push_swap.h"

stack	*ft_lstnew(int content)
{
	stack	*new_node;

	new_node = (stack *)malloc(sizeof(stack));
	if (!new_node)
		exit_with_message("Error In Allocation\n");
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

int *av_to_tab(int ac, char **av)
{
    int i;
    int *tab;

    i = 1;
    tab = (int *)malloc(sizeof(int) * ac);
    if (!tab)
        exit_with_message("Error In Allocation\n");
    while (i < ac)
    {
        tab[i] = ft_atoi(av[i]);
        i++;
    }
    return (tab);
}

void    fill_stack(stack **a, int ac, char **av)
{
    int *tab;
    int i;

    tab = av_to_tab(ac, av);
    input_check(ac, tab);
    i = ac;
    while (i > 0)
    {
        ft_lstadd_front(a, ft_lstnew(tab[i]));
        i--;
    }
}
    