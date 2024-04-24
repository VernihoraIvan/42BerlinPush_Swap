/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:00:14 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/22 15:32:56 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *a)
{
	int	i;
	int	median;

	i = 0;
	if (!a)
		return ;
	median = stack_len(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->is_above_median = 1;
		else
			a->is_above_median = 0;
		a = a->next;
		++i;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack			*current_b;
	t_stack			*target;
	int				best_match_index;

	while (a)
	{
		best_match_index = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a->target = find_max_number(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	calc_pushcost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if ((a->is_above_median) == 0)
			a->push_cost = len_a - a->index;
		if (a->target->is_above_median == 1)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

void	define_cheapest(t_stack *a)
{
	int		cheapest_cost;
	t_stack	*cheapest_node;

	if (!a)
		return ;
	cheapest_cost = INT_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_cost)
		{
			cheapest_cost = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->is_cheapest = 1;
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data
				&& current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
