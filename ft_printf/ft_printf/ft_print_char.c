/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:39:02 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/23 14:39:25 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(va_list arg)
{
	char	chr;

	chr = va_arg(arg, int);
	return ((int) write(1, &chr, 1));
}
