#include "../push_swap.h"

void    push_smallest_to_b(stack **a, stack **b)
{
    stack *tmp = *a;
    int smallest;
    int index;
    int smallest_index;

    smallest = (*a)->data;
    index = 0;
    while (tmp)
    {
        if (tmp->data < smallest)
        {
            smallest = tmp->data;
            smallest_index = index;
        }
        tmp = tmp->next;
        index++;
    }
    index = 0;
    while (index < smallest_index)
    {
        ra(a);
        index++;
    }
    pb(a, b);
}

void    insert_in_the_correct_position(stack **a, stack **b)
{
    stack *tmp = *a;
    int value;
    int index;
    int i;

    value = (*b)->data;
    index = 0;
    while (tmp && tmp->data < value)
    {
        tmp = tmp->next;
        index++;
    }
    i = 0;
    while (i < index)
    {
        ra(a);
        i++;
    }
    pa(a, b);
    while (i > 0)
    {
        rra(a);
        i--;
    }
}

void sort_five(stack **a, stack **b)
{
    int i;
    int count;
    stack *tmp = *a;

    count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    i = 0;
    if (count == 4)
        push_smallest_to_b(a, b);
    else
        while (i < 2)
        {
            push_smallest_to_b(a, b);
            i++;
        }
    if ((*b)->next && (*b)->data < (*b)->next->data)
        sb(*b);  // Pass the stack, not a single node
    sort_three(a);
    while (*b != NULL)
        insert_in_the_correct_position(a, b);
}
