/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:32:44 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/15 14:21:53 by iverniho         ###   ########.fr       */
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

// void sort_stacks(t_stack **a, t_stack **b)
// {
//     int len_a;

//     len_a = check_input(*a);
//     if (len_a-- > 3 && !is_stack_sorted(*a))
//         pb(b, a);
//     if (len_a-- > 3 && !is_stack_sorted(*a))
//         pb(b, a);
//     while (len_a-- > 3 && !is_stack_sorted(*a))
//     {
//         init_nodes_a(*a, *b);
//         move_a_to_b(a, b);
//     }
//     sort_three(a);
//     while (*b)
//     {
//         init_nodes_b(*a, *b);
//         move_b_to_a(a, b);
//     }
//     current_index(*a);
//     min_on_top(a);
// }

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
