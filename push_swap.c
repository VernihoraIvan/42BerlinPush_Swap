/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/12 14:59:07 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	ft_printf("argv[0] = %s\n", argv[0]);
	ft_printf("argv[1] = %s\n", argv[1]);
	ft_printf("argv[2] = %s\n", argv[2]);
	return (0);
}
