/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:11:28 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/18 12:14:45 by iverniho         ###   ########.fr       */
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

int	init_stack(t_stack **stack, char **array)
{
	int	i;
	int	j;
	int	c;

	i = 0;

	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '-')
				j++;
			if (!ft_isdigit(array[i][j]))
			{
				ft_printf("Error\nOnly digits allowed\n");
				return (0);
				// exit(EXIT_FAILURE);
			}
			j++;
		}
		// if (!ft_isdigit(array[i]))
		// 	return(ft_printf("Error\nOnly digits allowed\n"));
		// 	exit(EXIT_FAILURE);
		c = ft_atoi(array[i]);
		if (check_duplicat(*stack, c) == 0)
		{
			free_stack(stack);
			return (0);
		}
		append_node(stack, c);
		i++;
	}
	return (1);
}

void	append_node(t_stack **stack, int c)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->data = c;
	new->is_cheapest = 0;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack))
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	check_duplicat(t_stack *lst, int c)
{
	if (lst == NULL)
		return (1);
	while (lst)
	{
		if (lst->data == c)
			return (ft_printf("Error\nNo duplicats allowed\n"), 0);
		lst = lst->next;
	}
	return (1);
}
