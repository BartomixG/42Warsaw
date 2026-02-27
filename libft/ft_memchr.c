/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:04:38 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/15 17:07:48 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *) s;
	if (n > 0)
	{
		while (i < n)
		{
			if (((unsigned char) p[i] == (unsigned char) c))
			{
				return ((void *) &p[i]);
			}
			i++;
		}
	}
	return (NULL);
}
