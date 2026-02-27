/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:37:31 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/23 13:40:19 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr(int nb)
{
	int		counter;
	char	chr;

	counter = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		counter++;
	}
	if (nb > 9)
		counter += ft_putnbr(nb / 10);
	chr = (nb % 10) + 48;
	write(1, &chr, 1);
	return (counter + 1);
}

int	ft_print_dec(va_list arg)
{
	int		nb;

	nb = va_arg(arg, int);
	return (ft_putnbr(nb));
}
