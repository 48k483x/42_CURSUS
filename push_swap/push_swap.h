#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>

typedef struct node {
    int data;
    struct node *next;
} stack;

/* itoa */
size_t	count_word_str(long nb);
void	*allocation_str(size_t len);
char	*if_zero(char *str);
char	*ft_itoa(int n);

/* function to add */
void	ft_lstadd_front(stack **ab, stack *new);
stack	*ft_lstnew(int content);
stack	*ft_lstlast(stack *lst);

/* fill the stack functions */
int *av_to_tab(int ac, char **av);
void    fill_stack(stack **a, int ac, char **av);

/* input check functions */
bool    integer_check(int *tab, int ac);
bool   double_Check(int *tab, int ac);
bool    input_check(int ac, int *tab);

/* ft_atoi */
int ft_atoi(char *s);

/* exit lia bwa7ed message */
void    exit_with_message(char *s);

/* sort there random nums */
void    sort_three(stack **a);
void    sort_five(stack **a, stack **b);

/* moves*/
void    pa(stack **a, stack **b);
void    pb(stack **a, stack **b);
void    sa(stack *a);
void    sb(stack *b);
void    ss(stack *a, stack *b);
void    ra(stack **a);
void    rb(stack **b);
void    rr(stack **a, stack **b);
void    rra(stack **a);
void    rrb(stack **b);
void    rrr(stack **a, stack **b);

#endif // PUSH_SWAP_H