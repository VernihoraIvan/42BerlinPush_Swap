/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/18 12:55:29 by iverniho         ###   ########.fr       */
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

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv[0])
	{
		free_array(argv);
		return (ft_printf("Error\n"), 1);
	}
	if (!init_stack(&a, argv))
	{
		free_array(argv);
		free_stack(&a);
		return (1);
	}
	if (!is_stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three_el(&a);
		else
			sort_stacks(&a, &b);
	}
	print_stack(a, stack_len(a));
	free_array(argv);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
