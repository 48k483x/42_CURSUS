#include "../push_swap.h"

int get_pivot(stack **a, int size)
{
    if (a == NULL || *a == NULL || size == 0)
        return -1;
    srand(time(NULL));  // Seed the random number generator
    int index;
    int pivot;
    stack *tmp;

    do {
        index = rand() % size;  // Generate a random index
        tmp = *a;
        for (int i = 0; i < index; i++)
            tmp = tmp->next;
        pivot = tmp->data;  // Get the data at the random index
    } while (!check_pivot(a, pivot));  // Repeat until a valid pivot is found

    return pivot;
}

// int get_pivot(stack **a, int size)
// {
//     if (a == NULL || *a == NULL || size < 3)
//         return -1;

//     int first = (*a)->data;
//     int last = get_last(a);
//     int middle = get_middle(a, size);

//     if ((first < middle && middle < last) || (last < middle && middle < first))
//         return middle;
//     else if ((middle < first && first < last) || (last < first && first < middle))
//         return first;
//     else
//         return last;
// }

// int get_last(stack **a)
// {
//     stack *tmp = *a;
//     while (tmp->next)
//         tmp = tmp->next;
//     return tmp->data;
// }

// int get_middle(stack **a, int size)
// {
//     stack *tmp = *a;
//     for (int i = 0; i < size / 2; i++)
//         tmp = tmp->next;
//     return tmp->data;
// }

// int get_pivot(stack **a, int size)
// {
//     int i;
//     stack *tmp = NULL;
//     i = 0;
//     if (a == NULL || *a == NULL)
//         return -1;
//     tmp = *a;
//     while (tmp && i < size)
//     {
//         if (check_pivot(a, tmp->data))
//             return tmp->data;
//         tmp = tmp->next;
//         i++;
//     }
//     return -1;
// }

int  choose_pivot(stack **a)
{
    return (get_pivot(a, (stack_size(a))));
}
int check_pivot(stack **a, int pivot) {
    stack *tmp = *a;
    while (tmp && tmp->data != pivot) {
        if (tmp->data > pivot)
            return 1;  // There's at least one number before the pivot that's greater than the pivot
        tmp = tmp->next;
    }
    return 0;  // All numbers before the pivot are not greater than the pivot
}

void    to_head(stack **a, stack *s, int *i)
{
    if (a == NULL || *a == NULL || s == NULL)
        return;
    while ((*a)->data != s->data)
    {
        if (*i <= stack_size(a) / 2)
            rra(a);
        else if (*i >= stack_size(a) / 2)
            ra(a);
    }
}

void pivot_to_head(stack **a, int pivot)
{
    int distance = 0;
    stack *tmp = *a;

    while (tmp->data != pivot)
    {
        tmp = tmp->next;
        distance++;
    }
    while ((*a)->data != pivot)
    {
        if (distance <= stack_size(a) / 2)
            ra(a);
        else
            rra(a);
    }
}
bool reverse_sorted(stack **a)
{
    stack *tmp = *a;
    while (tmp->next)
    {
        if (tmp->data < tmp->next->data)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

void sort_quick(stack **a, stack **b)
{
    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return;
    int pivot;
    int less_than_pivot = 0;
    stack *tmp = NULL;
    int len = stack_size(a);
    if (len <= 1)
        return;
    tmp = *a;
    pivot = choose_pivot(a);
    if (pivot == -1)
        return ;
    // printf("pivot = %d\n", pivot);
    while (tmp)
    {
        if (tmp->data < pivot)
            less_than_pivot++;
        tmp = tmp->next;
    }
    while (less_than_pivot > 0)
    {
        if ((*a)->data < pivot)
        {
            pb(a, b);
            less_than_pivot--;
        }
        else
            rra(a);
    }
    printf("pivot = %d\n", pivot);
    pivot_to_head(a, pivot);
    if (pivot == -1)
        return ;
    print_stack(*a);
    print_stack(*b);
    if (pivot == -1)
        return ;
    sort_quick(a, b);
    while (*b)
        pa(a, b);
    sort_quick(a, b);
}

