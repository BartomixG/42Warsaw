/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:17:15 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:03:02 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			in;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		in = 0;
		if (big[i] == little[in])
		{
			while (big[i] != '\0' && i + in < len)
			{
				if (big[i + in] != little[in])
					break ;
				if (little[in + 1] == '\0')
					return ((char *) &big[i]);
				in++;
			}
		}
		i++;
	}
	return (NULL);
}
