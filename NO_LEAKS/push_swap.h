/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:47 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/14 08:45:31 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <assert.h>
# include <unistd.h>
# include <string.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_stack;

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
bool				input_check(int ac, int *tab, t_stack **a, char **av);
bool				is_valid_integer(int ac, char **av, int *i, int *j);

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
void				quick_divide_qs(t_stack **a,
						t_stack **b, int interval, int size);
void				move_max_up(t_stack **b);
void				sort(t_stack *a, t_stack *b, int arr_num);

/* moves*/
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif // PUSH_SWAP_H
