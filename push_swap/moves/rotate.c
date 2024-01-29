#include "../push_swap.h"

stack	*ft_lstlast(stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void ra(stack **a)
{
    stack *first;
    stack *last;

    if (!(*a) || !(*a)->next)
        return;

    first = *a;
    *a = (*a)->next;
    first->next = NULL;

    last = *a;
    while (last->next != NULL)
        last = last->next;

    last->next = first;

    write(1, "ra\n", 3);
}


/*int	ra(stack **a)
{
	stack	*head;
	stack	*tail;

	if (!(*a) || !(*a)->next)
        return ;
	head = *a;
	tail = ft_lstlast(head);
	*a = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}*/

void    rb(stack **b)
{
    stack *last;
    stack *current;

    if (!(*b) || !(*b)->next)
        return ;
    last = (*b);
    *b = (*b)->next;
    current = (*b);
    while (current->next)
        current = current->next;
    current->next = last;
    last->next = NULL;
    write(1, "rb\n", 3);
}

void    rr(stack **a, stack **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}