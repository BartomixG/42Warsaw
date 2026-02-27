/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:10:27 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:02:04 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**putting_strs(char **arr, char c, char const *s)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (i < ft_words(s, c))
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j])
			j++;
		arr[i] = ft_substr(s, start, j - start);
		if (!arr[i])
		{
			free_all(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = putting_strs(arr, c, s);
	if (!arr)
		return (NULL);
	return (arr);
}
