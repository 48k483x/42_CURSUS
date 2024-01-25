#include "push_swap.h"

void	ft_lstadd_back(stack **ab, stack *new)
{
	stack	*current;

	current = *ab;
	if (*ab == NULL)
	{
		*ab = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
    current->next->next = NULL;
}

void    ra(stack **a)
{
    stack *new;
    stack *old_head;

    if (!(*a) || !(*a)->next)
        return ;
    new = malloc(sizeof(stack));
    if (!new) 
        return ;
    old_head = (*a);
    new->data = (*a)->data;
    ft_lstadd_back(a, new);
    (*a) = (*a)->next;
    free(old_head);
}

void    rb(stack **b)
{
    stack *new;
    stack *old_head;

    if (!(*b) || !(*b)->next)
        return ;
    new = malloc(sizeof(stack));
    if (!new) 
        return ;
    old_head = (*b);
    new->data = (*b)->data;
    ft_lstadd_back(b, new);
    (*b) = (*b)->next;
    free(old_head);
}

void    rr(stack **a, stack **b)
{
    ra(a);
    rb(b);
}