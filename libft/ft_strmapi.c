/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:10:53 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/16 22:55:25 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*result;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	result = ft_strdup((char *) s);
	if (!result)
		return (NULL);
	size = ft_strlen(s);
	while (size >= 1)
	{
		result[size -1] = f((unsigned int)(size - 1), result[size - 1]);
		size--;
	}
	return (result);
}
