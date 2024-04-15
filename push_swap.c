/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/15 14:31:32 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *lst, int s)
{
	int i;

	i = 0;
	if (lst == NULL)
		return;
	while (i < s)
	{
		printf("element: %d\n", lst->data);
		lst = lst->next;
		i++;
	}
}

int is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (ft_printf("no stack\n"), 0);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (ft_printf("not sorted\n"), 0);
		stack = stack->next;
	}
	return (ft_printf("sorted\n"), 1);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int len;
	char **array;

	len = 0;
	a = NULL;
	b = NULL;
	array = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	len = check_input(array);
	if (!len)
		return (ft_printf("Error\n"), 0);

	init_stack(&a, array);
	printf("len %d\n", len);
	if (!is_stack_sorted(a))
	{
		if (len == 2)
			sa(&a);
		if (len == 3)
			sort_three_el(&a);
		// printf("no\n");
		// else
		// sort_stacks(&a, &b);
	}
	print_stack(a, len - 1);
	print_stack(b, 1);
	free_array(array);

	free_stack(&a);
	free_stack(&b);

	return (0);
}
