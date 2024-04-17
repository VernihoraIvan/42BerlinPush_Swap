/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:47:53 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/17 16:36:26 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **a)
{
    if (!*a || !(*a)->next)
        return;
    *a = (*a)->next;
    (*a)->prev->prev = *a;
    (*a)->prev->next = (*a)->next;
    if ((*a)->next)
        (*a)->next->prev = (*a)->prev;
    (*a)->next = (*a)->prev;
    (*a)->prev = NULL;
}

void sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
