/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:07:06 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:03:09 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0' && i < n - 1)
	{
		if ((unsigned char) s1[i] == (unsigned char) s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
