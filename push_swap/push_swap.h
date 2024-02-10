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
/*size_t	count_word_str(long nb);
void	*allocation_str(size_t len);
char	*if_zero(char *str);
char	*ft_itoa(int n);*/

/* function to add */
void	ft_lstadd_front(stack **ab, stack *new);
stack	*ft_lstnew(int content);
stack	*ft_lstlast(stack *lst);

/* fill the stack functions */
int     *av_to_tab(int ac, char **av);
void    fill_stack(stack **a, int ac, char **av);

/* input check functions */
bool    integer_check(int *tab, int ac);
bool    double_Check(int *tab, int ac);
bool    input_check(int ac, int *tab, stack **a);
bool    is_valid_integer(int ac, char **av);

/* ft_split */
int     count_strings(char const *s, char c);
char	*malloc_strings(const char *s, char c);
char	**ft_split(char const *s, char c);
void    free_split(char **split);

/* parsing */
char     ***_parsed_av(int ac, char **av);
int     _parsed_array_num(char ***tab);
char    **_parsed_arr(char ***tab);

/* ft_atol */
long long ft_atol(char *nptr);
int ft_isdigit(int c);

/* exit lia bwa7ed message */
void    exit_with_message(char *s);

/* free lia stack dial **a */
void    free_stack(stack **a);

/* sort there random nums */
void    sort_three(stack **a);
void    sort_four(stack **a, stack **b);
void    sort_five(stack **a, stack **b);
void    min_to_b(stack **a, stack **b);

/* sorting utils */
int     stack_size(stack **a);
stack   *stack_smallest(stack **a);
stack   *stack_biggest(stack **a);

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