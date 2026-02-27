/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:44:15 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:02:20 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	if (*s != 0)
	{
		while (*s)
		{
			if ((unsigned char)*s == (unsigned char)c)
			{
				p = (char *) s;
				return (p);
			}
			s++;
		}
	}
	if ((unsigned char)*s == (unsigned char)c)
		p = (char *)s;
	return (p);
}
