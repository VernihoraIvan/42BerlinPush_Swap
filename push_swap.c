/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:50:12 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/12 18:12:45 by iverniho         ###   ########.fr       */
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

int	check_input(char **str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (is_input_correct(str[i]) == 0)
			return (0);
		len++;
		i++;
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
	init_stack(&a, array);
	print_stack(a);
	free_array(array);
	free_stack(&a);

	return (0);
}

