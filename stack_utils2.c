/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:35:01 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/22 15:30:03 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	node_to_top(a, (*b)->target, 'a');
	pa(a, b);
}
