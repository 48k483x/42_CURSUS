#include "push_swap.h"

void    exit_with_message(char *s)
{
    while (*s)
        write(2, s++, 1);
    exit(1);
}


int main(int ac, char **av) 
{
    stack *a = NULL;
    stack *b = NULL;
    int arr_num;

    char **arr = _parsed_arr(_parsed_av(ac, av));
    arr_num = 0;
    while (arr[arr_num])
           arr_num++;
    fill_stack(&a, arr_num, arr);
    if (arr_num == 2 && a->data > a->next->data)
        sa(a);
    else if (arr_num == 3)
        sort_three(&a);
    else if (arr_num == 4)
        sort_four(&a, &b);
    else if (arr_num == 5)
        sort_five(&a, &b);
    else
    {
        quick_divide_QS(&a, &b, find_interval(&a), stack_size(&a));
        while (b)
        {
            move_max_up(&b);
            pa(&a, &b);
        }
    }
    // print_stack(a);
    free_split(arr);
    free_stack(&a);
}


// current = a;
    // printf("head\n");
    // while (current != NULL)
    // {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }
    // printf("NULL\n");
