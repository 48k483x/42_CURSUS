/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:57:05 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/18 20:52:14 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"
# include <stdio.h>
# include <stdlib.h>

void	start_cheking(t_stack **a, t_stack **b);
void	apply_operations(t_stack **a, t_stack **b, char *line);
void	_sa(t_stack **a);
void	_sb(t_stack **b);
void	_ss(t_stack **a, t_stack **b);
void	_pa(t_stack **a, t_stack **b);
void	_pb(t_stack **a, t_stack **b);
void	_ra(t_stack **a);
void	_rb(t_stack **b);
void	_rr(t_stack **a, t_stack **b);
void	_rra(t_stack **a);
void	_rrb(t_stack **b);
void	_rrr(t_stack **a, t_stack **b);

#endif // !PUSH_SWAP_BONUS_H
