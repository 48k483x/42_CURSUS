/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:19:48 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/19 23:27:29 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// ** PARSING UTILS **
int					av_error(char *str);
int					dup_error(t_stack *a, long long n);
void				error_generator(void);
long long			ft_atol(const char *str);

// ** ACTIONS **
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// ** t_stack UTILS **
t_stack				*create_node(int n);
void				push(t_stack **s, int n);
int					pop(t_stack **s);
void				initialize_stack(t_stack **a, int ac, char **av);
void				print_stack(t_stack *s);
int					stack_size(t_stack *s);
int					sorted(int a, int b);
int					stack_sorted(t_stack *s, int (*sorted)(int, int));
void				swap(int *a, int *b);
t_stack				*stack_bottom(t_stack *s);
t_stack				*stack_top(t_stack *s);
t_stack				*stack_min(t_stack *s);
t_stack				*stack_max(t_stack *s);
int					max_index(t_stack *b);
void				insertion_sort(int *arr, int size);
void				min_to_b(t_stack **a, t_stack **b);
int					get_range(t_stack *a);
void				max_to_top(t_stack **b);
void				free_stack(t_stack **s);

// ** SORTING UTILS **
void				start_sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_others(t_stack **a, t_stack **b, int range, int size);
int					*stack_to_sarray(t_stack *s);

#endif // !PUSH_SWAP_H