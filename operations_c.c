/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:56:17 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/15 17:40:30 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_stack **a)
{
    t_stack *last;

    last = find_last(*a);
    last->prev->next = NULL;
    last->next = *a;
    last->prev = NULL;
    *a = last;
    last->next->prev = last;
}

void rra(t_stack **a)
{
    rev_rotate(a);
    ft_printf("rra\n");
}

void rrb(t_stack **b)
{
    rev_rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_printf("rrr\n");
}
