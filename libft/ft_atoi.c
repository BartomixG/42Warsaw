/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 01:48:26 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:00:36 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

static int	ft_sign(const char *str, int *i)
{
	if (str[*i] == '+')
	{
		(*i)++;
		return (2);
	}
	else if (str[*i] == '-')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long		nb;
	int			i;
	int			sign;

	i = spaces(nptr);
	sign = ft_sign(nptr, &i);
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb += nptr[i] - 48;
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			nb *= 10;
		i++;
	}
	if (sign == 1)
		nb *= -1;
	return ((int) nb);
}
