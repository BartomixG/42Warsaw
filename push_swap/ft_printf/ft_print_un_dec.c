/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:12:46 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/31 20:42:23 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_un_nbr(unsigned int nb)
{
	int				counter;
	char			chr;

	counter = 0;
	if (nb > 9)
		counter += ft_put_un_nbr(nb / 10);
	chr = (nb % 10) + 48;
	write(1, &chr, 1);
	return (counter + 1);
}

int	ft_print_un_dec(va_list arg)
{
	int	nb;

	nb = va_arg(arg, int);
	return (ft_put_un_nbr((unsigned int) nb));
}
