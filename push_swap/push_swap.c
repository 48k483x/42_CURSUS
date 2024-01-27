#include "push_swap.h"

void    exit_with_message(char *s)
{
    while (*s)
        write(1, s++, 1);
    exit(1);
}

int main(int ac, char **av) 
{
    stack *a = NULL;
    //stack *b = NULL;

    fill_stack(&a, ac, av);
    stack *current = NULL;
    current = a;
    printf("head\n");
    while (current->next != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("NULL\n");
    if (ac == 3 && (a->data > a->next->data))
            sa(a);
    else if (ac == 4)
        sort_three(&a);
    /*else if (ac == 6)
        sort_five(&a);*/
    current = a;
    printf("head\n");
    while (current->next != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("NULL\n");
}