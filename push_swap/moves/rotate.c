#include "../push_swap.h"

void    ra(stack **a)
{
    stack *last;
    stack *current;

    if (!(*a) || !(*a)->next)
        return ;
    last = (*a);
    *a = (*a)->next;
    current = (*a);
    while (current->next)
        current = current->next;
    current->next = last;
    last->next = NULL;
    write(1, "ra\n", 3);
}

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