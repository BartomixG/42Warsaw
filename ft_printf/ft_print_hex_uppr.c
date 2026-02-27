/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uppr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:47:53 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/31 20:35:08 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned int nbr, char *base)
{
	char	chr;
	int		counter;

	counter = 0;
	if (nbr > 15)
		counter += ft_print_hex(nbr / 16, "0123456789ABCDEF");
	chr = base[nbr % 16];
	write (1, &chr, 1);
	return (counter + 1);
}

int	ft_print_hex_uppr(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_print_hex(nb, "0123456789ABCDEF"));
}
