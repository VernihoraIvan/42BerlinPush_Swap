/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:15:29 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/17 14:50:31 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	is_input_correct(char *str_n)
{
	int	i;

	i = 0;
	if (!(str_n[i] == '+' || str_n[i] == '-' \
			|| (str_n[i] >= '0' && str_n[i] <= '9')))
		return (0);
	if ((str_n[i] == '+' || str_n[i] == '-') \
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (0);
	if (str_n[i] == '+' || str_n[i] == '-')
		i++;
	while (str_n[i])
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
