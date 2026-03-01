/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:48:21 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:03:18 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s != 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			p = (char *) s;
		}
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		p = (char *)s;
	return (p);
}
