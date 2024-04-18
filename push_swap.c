/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/18 13:39:21 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *lst, int s)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return ;
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

int static	free_program(t_stack **a, t_stack **b, char **argv, char s)
{
	if (s == '1')
	{
		ft_printf("Error111\n");
		free_array(argv);
	}
	if (s == '2')
	{
		free_stack(a);
		free_stack(b);
		free_array(argv);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv[0])
		return (free_program(&a, &b, argv, '1'));
	if (!init_stack(&a, argv))
		return (free_program(&a, &b, argv, '2'));
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
	free_program(&a, &b, argv, '2');
	return (0);
}
