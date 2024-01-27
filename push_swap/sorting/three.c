#include "../push_swap.h"

void    sort_three(stack **a)
{ //3 2 1   3 1 2   2 3 1   2 1 3   1 3 2   1 2 3
    int n1;//3
    int n2; //2
    int n3; //1

    n1 = (*a)->data;
    n2 = (*a)->next->data;
    n3 = (*a)->next->next->data;
    if (n1 > n2 && n2 < n3 && n1 < n3)
        sa(*a);
    else if (n1 > n2 && n2 < n3 && n1 > n3)
    {
        ra(a);
        //rra(a);
    }
    else if (n1 < n2 && n2 > n3)
        ra(a);
    else if (n1 < n2 && n2 > n3 && n1 > n3)
    {
        sa(*a);
        ra(a);
    }
    else if (n1 > n2 && n2 < n3 && n1 > n3)
        rra(a);
}
