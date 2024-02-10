#include "../push_swap.h"

stack    *stack_smallest(stack **a)
{
    stack *tmp = *a;
    stack *smallest = *a;

    while (tmp)
    {
        if (tmp->data < smallest->data)
            smallest = tmp;
        tmp = tmp->next;
    }
    return (smallest);
}

stack *stack_biggest(stack **a)
{
    stack *tmp = *a;
    stack *biggest = *a;
    
    while (tmp)
    {
        if (tmp->data > biggest->data)
            biggest->data = tmp->data;
        tmp = tmp->next;
    }
    return (biggest);
}

int stack_size(stack **a)
{
    if (*a == NULL)
        return (0);
    else
        return (1 + stack_size(&(*a)->next));
}