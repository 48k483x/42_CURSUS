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
    stack *current = NULL;
    fill_stack(&a, ac, av);
    // current = a;
    // printf("head\n");
    // while (current != NULL)
    // {
    //     printf("%d\n", current->data);
    //     current = current->next;
    // }
    // printf("NULL\n");
    if (ac == 3 && a->data > a->next->data)
        sa(a);
    else if (ac == 4)
        sort_three(&a);
    else if (ac > 4 && ac < 7)
        sort_five(&a, &b);
    printf("head\n");
    current = a;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


// stack *new_node(int data)
// {
//     stack *node = malloc(sizeof(stack));
//     if (!node)
//     {
//         fprintf(stderr, "Memory allocation failed\n");
//         exit(EXIT_FAILURE);
//     }
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// int main(void) 
// {
//     stack *a = NULL;
//     stack *current = NULL;

//     // Manually create a stack with three numbers
//     a = new_node(3);
//     a->next = new_node(1);
//     a->next->next = new_node(2);

//     // Print the initial stack
//     printf("Initial stack:\n");
//     current = a;
//     while (current != NULL)
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//     }

//     // Apply the ra operation
//     ra(&a);

//     // Print the stack after the ra operation
//     printf("Stack after ra:\n");
//     current = a;
//     while (current != NULL)
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//     }

//     return 0;
// }