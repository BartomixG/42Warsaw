/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:23:54 by bgorski           #+#    #+#             */
/*   Updated: 2025/11/22 15:05:46 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_hex(unsigned int nbr, char *base)
{
	char	chr;
	int		counter;

	counter = 0;
	if (nbr > 15)
		counter += ft_print_hex(nbr / 16, "0123456789abcdef");
	chr = base[nbr % 16];
	write (1, &chr, 1);
	return (counter + 1);
}

int	ft_print_hex_low(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_print_hex(nb, "0123456789abcdef"));
}
