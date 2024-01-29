#include "../push_swap.h"

void    sort_five(stack **a, stack **b)
{
    pb(a, b);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
}