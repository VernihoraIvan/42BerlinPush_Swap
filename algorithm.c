/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:32:44 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/16 16:10:17 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_max_number(t_stack *stack)
{
	int max;
	t_stack *max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		printf("stack->data %d\n", stack->data);
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void current_index(t_stack *a)
{
	int i;
	int median;

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
		i++;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
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
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
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

static void	define_cheapest(t_stack *a)
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

void create_node_a(t_stack **a, t_stack **b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	calc_pushcost_a(a, b);
	define_cheapest(a);
}

void sort_stacks(t_stack **a, t_stack **b)
{

	int len_a;

	len_a = check_input(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		create_node_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void sort_three_el(t_stack **a)
{
    t_stack *biggest;

    biggest = find_max_number(*a);
    printf("biggest %d\n", biggest->data);
    if (biggest == *a)
        ra(a);
    else if ((*a)->next == biggest)
        rra(a);
    if ((*a)->data > (*a)->next->data)
        sa(a);
}
