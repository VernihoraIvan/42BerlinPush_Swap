/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/12 19:04:11 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_stack(t_stack *lst)
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		printf("lst_data %d\n",lst->data);
		lst = lst->next;
	}
}

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	char	**array;

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
	if (is_stack_sorted(a))
		return (printf("yes\n"), 1);
	else
		return (printf("no\n"), 0);
	init_stack(&a, array);
	print_stack(a);
	free_array(array);
	free_stack(&a);

	return (0);
}

