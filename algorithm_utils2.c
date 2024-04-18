/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:32:10 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/18 14:34:34 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	min_on_top(t_stack **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->is_above_median == 1)
			ra(a);
		else
			rra(a);
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->is_above_median == 1 \
		&& cheapest->target->is_above_median == 1)
		rotate_a_b(a, b, cheapest);
	else if (cheapest->is_above_median == 0 \
		&& cheapest->target->is_above_median == 0)
		rev_rotate_a_b(a, b, cheapest);
	node_to_top(a, cheapest, 'a');
	node_to_top(b, cheapest->target, 'b');
	pb(b, a);
}

void	sort_three_el(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max_number(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
