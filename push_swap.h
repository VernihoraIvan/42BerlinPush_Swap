/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:09 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/12 14:56:17 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

typedef struct s_stack_node
{
	int				data;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

#endif
