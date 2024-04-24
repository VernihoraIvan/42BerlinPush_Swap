/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:11:28 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/24 15:59:32 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long static	ft_atol(const char *str)
{
	long	res;
	int		i;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		return (res);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	init_stack(t_stack **stack, char **array)
{
	int		i;
	int		j;
	long	c;

	i = -1;
	while (array[++i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '-')
				j++;
			if (ft_isdigit(array[i][j]) == 0)
				return (ft_printf("Error\nOnly digits allowed\n"), 0);
			j++;
		}
		c = ft_atol(array[i]);
		if (c > INT_MAX || c < INT_MIN)
			return (ft_printf("Error\nNumber out of range\n"), 0);
		c = (int)c;
		if (check_duplicat(*stack, c) == 0)
			return (free_stack(stack), 0);
		append_node(stack, c);
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
