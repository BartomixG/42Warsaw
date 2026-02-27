/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:07:20 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/23 13:41:10 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (write (1, "(null)", 6));
	return ((int) write(1, str, ft_strlen(str)));
}
