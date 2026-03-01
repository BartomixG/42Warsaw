/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:34:17 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/31 20:37:07 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_hex(unsigned long ptr, char *base)
{
	char	chr;
	int		counter;

	counter = 0;
	if (ptr > 15)
		counter += ft_ptr_hex(ptr / 16, "0123456789abcdef");
	chr = base[ptr % 16];
	write (1, &chr, 1);
	return (counter + 1);
}

int	ft_print_ptr(va_list arg)
{
	void	*ptr;

	ptr = va_arg(arg, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	return (ft_ptr_hex((unsigned long) ptr, "0123456789abcdef") + 2);
}
