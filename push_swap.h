/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:09 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/18 12:14:17 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	int				is_above_median;
	int				is_cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

t_stack	*find_last(t_stack *lst);
int		init_stack(t_stack **stack, char **array);
void	append_node(t_stack **stack, int c);
void	free_stack(t_stack **stack);
int		check_input(t_stack *stack);
void	free_array(char **array);
int		is_input_correct(char *str_n);
int		check_duplicat(t_stack *lst, int c);
int		is_stack_sorted(t_stack *stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
void	sort_three_el(t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
int		stack_len(t_stack *stack);
void	print_stack(t_stack *lst, int s);
t_stack	*find_min(t_stack *a);
#endif
