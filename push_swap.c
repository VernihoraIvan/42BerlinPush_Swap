/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/25 16:00:56 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		printf("element: %d\n", lst->data);
		lst = lst->next;
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
		ft_printf("Error1\n");
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

void	duplicate_argv_to_array(char **array, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (argv[j])
		array[i++] = ft_strdup(argv[j++]);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**array;

	a = ((b = NULL, array = NULL), NULL);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
		array = (char **)malloc(sizeof(char *) * (argc));
	if (argc > 2)
		duplicate_argv_to_array(array, argv);
	if (!array[0] || !init_stack(&a, array))
		return (free_program(&a, &b, array, '1'), 1);
	if (!is_stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three_el(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_program(&a, &b, array, '2'), 0);
}
