/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:00:00 by iverniho          #+#    #+#             */
/*   Updated: 2024/04/18 12:59:20 by iverniho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	count_len(const char format, va_list args)
{
	int		len;

	len = 0;
	if (format == 'c')
	{
		ft_putchar(va_arg(args, int));
		len++;
	}
	else if (format == 'i' || format == 'd')
		len += ft_putnumber((va_arg(args, int)), 10);
	else if (format == 'x' || format == 'X')
		len += ft_puthex(format, (va_arg(args, unsigned int)));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == '%')
	{
		len++;
		write(1, "%%", 1);
	}
	else if (format == 'u')
		len += ft_putunnumber(va_arg(args, unsigned int));
	else if (format == 'p')
		len += ft_putpointer(va_arg(args, unsigned long long));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]) != 0)
		{
			len = len + count_len(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
