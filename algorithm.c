/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:32:44 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/17 17:54:54 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_number(t_stack *stack)
{
	int max;
	t_stack *max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
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

void	current_index(t_stack *a)
{
	int	i;
	int	median;

	// printf("test\n");
	// print_stack(a, stack_len(a));
	i = 0;
	if (!a)
		return ;
	median = stack_len(a) / 2;
	// printf("stack_len %d\n", stack_len(a));
	// printf("median %d\n", median);
	while (a)
	{
		// printf("a->data %d\n", a->data);

		a->index = i;
		if (i <= median)
			a->is_above_median = 1;
		else
			a->is_above_median = 0;
		// printf("a->index %d\n", a->index);
		// printf("a->is_above_median %d\n", a->is_above_median);
		a = a->next;
		++i;
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
			a->target = find_max_number(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	calc_pushcost_a(t_stack *a, t_stack *b)
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

void create_node_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	calc_pushcost_a(a, b);
	define_cheapest(a);
}

void	create_node_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

t_stack	*find_cheapest(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->is_cheapest == 1)
			return (a);
		a = a->next;
	}
	return (NULL);
}

t_stack	*find_min(t_stack *a)
{
	int		min;
	t_stack	*min_node;

	if (!a)
		return (NULL);
	min = INT_MAX;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

void	rotate_a_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while(*b != cheapest->target && *a != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_a_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while(*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}



void	node_to_top(t_stack **a, t_stack *node, char stack_name)
{
	while (*a != node)
	{
		if (stack_name == 'a')
		{
			if (node->is_above_median == 1)
				ra(a);
			else
				rra(a);
		}
		else if (stack_name == 'b')
		{
			if (node->is_above_median == 1)
				rb(a);
			else
				rrb(a);
		}
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	// printf("b->data %d\n", (*b)->data)
	// printf("a\n");
	// print_stack(*a, stack_len(*a));
	// printf("b\n");
	// print_stack(*b, stack_len(*b));
	node_to_top(a, (*b)->target, 'a');
	pa(a, b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->is_above_median == 1 && cheapest->target->is_above_median == 1)
		rotate_a_b(a, b, cheapest);
	else if (cheapest->is_above_median == 0 && cheapest->target->is_above_median == 0)
		rev_rotate_a_b(a, b, cheapest);
	node_to_top(a, cheapest, 'a');
	node_to_top(b, cheapest->target, 'b');
	pb(b, a);
}

void	min_on_top(t_stack **a)
{
	while((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->is_above_median == 1)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
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
	sort_three_el(a);

	// print_stack(*a, stack_len(*a));
	// print_stack(*b, stack_len(*b));
	while (*b)
	{
		create_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	sort_three_el(t_stack **a)
{
	t_stack *biggest;

	biggest = find_max_number(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
