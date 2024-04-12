/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:09 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/12 18:14:06 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*find_last(t_stack *lst);
void	init_stack(t_stack **stack, char **array);
void	append_node(t_stack **stack, int c);
void	free_stack(t_stack **stack);

#endif
