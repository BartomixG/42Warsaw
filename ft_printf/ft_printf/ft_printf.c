/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:31:02 by bgorski           #+#    #+#             */
/*   Updated: 2025/11/22 15:08:48 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_format(va_list arg, char c)
{
	int	sub_counter;

	if (c == 'c')
		sub_counter = ft_print_char(arg);
	else if (c == 's')
		sub_counter = ft_print_str(arg);
	else if (c == 'p')
		sub_counter = ft_print_ptr(arg);
	else if (c == 'd' || c == 'i')
		sub_counter = ft_print_dec(arg);
	else if (c == 'u')
		sub_counter = ft_print_un_dec(arg);
	else if (c == 'x')
		sub_counter = ft_print_hex_low(arg);
	else if (c == 'X')
		sub_counter = ft_print_hex_uppr(arg);
	else if (c == '%')
		sub_counter = ft_print_percnt();
	return (sub_counter);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			count;

	if (!str)
		return (-1);
	va_start(arg, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_print_format(arg, *str);
			str++;
		}
		else if (*str != 0)
			count += write (1, str++, 1);
	}
	va_end(arg);
	return (count);
}
