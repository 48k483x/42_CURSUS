
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <assert.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

typedef struct node
{
	int			data;
	struct node	*next;
}				t_stack;

typedef struct index
{
	int	i;
	int	j;
}		t_index;

/* function to add */
void				ft_lstadd_front(t_stack **ab, t_stack *new);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);

/* fill the stack functions */
int					*av_to_tab(int ac, char **av);
void				fill_stack(t_stack **a, int ac, char **av);

/* input check functions */
bool				integer_check(int *tab, int ac);
bool				double_check(int *tab, int ac);
bool				input_check(int ac, int *tab, char **av);
bool				is_valid_integer(int ac, char **av, t_index *index);

/* ft_split */
int					count_strings(char const *s, char c);
char				*malloc_strings(const char *s, char c);
char				**ft_split(char const *s, char c);
void				free_split(char **split);

/* parsing */
char				***_parsed_av(int ac, char **av);
int					_parsed_array_num(char ***tab);
char				**_parsed_arr(char ***tab);
void				free_triple_array(char ***tab);

/* ft_atol */
long long			ft_atol(char *nptr);
int					ft_isdigit(int c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *n);
bool				length_check(char **n);

/* exit lia bwa7ed message */
void				exit_with_message(char *s);

/* free lia stack dial **a */
void				free_stack(t_stack **a);

/* sort there random nums */
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				min_to_b(t_stack **a, t_stack **b);

/* sorting utils */
int					stack_size(t_stack **a);
t_stack				*stack_head(t_stack **a);
bool				sorted(t_stack **a);
t_stack				*stack_head(t_stack **a);
int					stack_biggest(t_stack **a);
t_stack				*stack_smallest(t_stack **a);
int					peak_index(t_stack **b, int peak);

/* Pb Rb to reduce lines nums*/
void				pb_rb(t_stack **a, t_stack **b, int *i);

/* Printing the stack */
void				print_stack(t_stack *s);

/* Stack to an Sorted array */
void				sort_int_array(int *tab, int size);
int					*sorted_stack_array(t_stack **a);

/* Sorting more than 5 nums */
int					find_interval(t_stack **a);
void				quick_divide_qs(t_stack **a, t_stack **b, \
									int interval, int size);
void				move_max_up(t_stack **a, t_stack **b);

/* push_swap.c */
void				free_all(t_stack *a, char **arr);
bool				is_space(char c);
int					arr_n(char **arr, char **av);
int					_strlen(const char *s);

/* moves*/
void				pa(t_stack **a, t_stack **b, int param);
void				pb(t_stack **a, t_stack **b, int param);
void				sa(t_stack *a, int param);
void				sb(t_stack *b, int param);
void				ss(t_stack *a, t_stack *b, int param);
void				ra(t_stack **a, int param);
void				rb(t_stack **b, int param);
void				rr(t_stack **a, t_stack **b, int param);
void				rra(t_stack **a, int param);
void				rrb(t_stack **b, int param);
void				rrr(t_stack **a, t_stack **b, int param);

#endif // PUSH_SWAP_H
