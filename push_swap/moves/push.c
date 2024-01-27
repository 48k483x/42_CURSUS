#include "../push_swap.h" 

void    pa(stack **a, stack **b)
{
    stack *tmp;

    if (*b)
    {
        tmp = (*b)->next;
        (*b)->next = (*a);
        (*a) = (*b);
        (*b) = tmp;
    }
    write(1, "pa\n", 3);
}

void    pb(stack **a, stack **b)
{
    stack *tmp;

    if (*a)
    {
        tmp = (*a)->next;
        (*a)->next = (*b);
        (*b) = (*a);
        (*a) = tmp;
    }
    write(1, "pb\n", 3);
}