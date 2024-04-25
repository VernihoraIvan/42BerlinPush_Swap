/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/25 13:45:57 by iverniho         ###   ########.fr       */
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
		ft_printf("Error\n");
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

// static void	initStack(t_stack **stack, int argc, char **argv)
// {
// 	t_stack	*new;
// 	char	**args;
// 	int		i;

// 	i = 0;
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		args = argv;
// 	}
// 	while (args[i])
// 	{
// 		new = ft_lstnew(ft_atoi(args[i]));
// 		ft_lstadd_back(stack, new);
// 		i++;
// 	}
// 	index_stack(stack);
// 	if (argc == 2)
// 		ft_free(args);
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**array;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	array = malloc(sizeof(char *) * (argc  ));
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		while (argv[i])
		{

			array[i] = ft_strdup(argv[i]);
			printf("array[%d]: %s\n", i, array[i]);
			i++;
		}
	}
	if (!array[0])
		return (free_program(&a, &b, array, '1'));
	// if (!init_stack(&a, &array[0]) && !init_stack(&a, array + 1))
	if (array == NULL || array + 1 == NULL)
		return (free_program(&a, &b, array, '1'));
	if (!init_stack(&a, &array[0]) && !init_stack(&a, array + 1))
		return (free_program(&a, &b, array, '1'));

	if (!is_stack_sorted(a))
	{

		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three_el(&a);
		else
			sort_stacks(&a, &b);
	}
	print_stack(a);
	free_program(&a, &b, array, '2');
	return (0);
}
