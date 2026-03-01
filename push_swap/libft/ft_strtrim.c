/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:59:02 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/16 22:48:22 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find_end(char *s1, char *set)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (s1[i] != 0)
	{
		if (in_set(s1[i], set) == 0)
			result = i;
		i++;
	}
	return (result);
}

static int	find_start(char *s1, char *set)
{
	int		i;

	i = 0;
	while (s1[i] != 0)
	{
		if (in_set(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		stop;
	char	*sub;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (!*s1)
	{
		sub = (ft_strdup(""));
		return (sub);
	}
	start = find_start((char *) s1, (char *) set);
	stop = find_end((char *) s1, (char *) set);
	if (start > stop)
	{
		sub = (ft_strdup(""));
		return (sub);
	}
	sub = ft_substr((char *) s1, start, (size_t)(stop - start + 1));
	return (sub);
}
