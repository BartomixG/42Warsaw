/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:11:51 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:01:04 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	ft_strrev(char *str)
{
	size_t	size;
	size_t	i;
	char	tmp;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
}

static char	*ft_zero(void)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

static size_t	nbr_of_chrs(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return ((size_t) i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	l;

	is_neg = (n < 0);
	if (n == 0)
		return (ft_zero());
	str = ft_calloc(nbr_of_chrs(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	l = 0;
	while (n != 0)
	{
		str[l] = '0' + ft_abs(n % 10);
		n = (n / 10);
		l++;
	}
	if (is_neg)
	{
		str[l] = '-';
		l++;
	}
	str[l] = 0;
	ft_strrev(str);
	return (str);
}
