#include "push_swap.h"

void    sa(stack *a)
{
    int tmp;

    if (a && a->next)
    {
        tmp = a->data;
        a->data = a->next->data;
        a->next->data = tmp;
    }
}

void    sb(stack *b)
{
    int tmp;

    if (b && b->next)
    {
        tmp = b->data;
        b->data = b->next->data;
        b->next->data = tmp;
    }
}

void    ss(stack *a, stack *b)
{
    sa(a);
    sb(b);
}