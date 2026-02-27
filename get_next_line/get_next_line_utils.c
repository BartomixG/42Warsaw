/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:20:10 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/02 13:52:22 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		return (ft_substr(s, 0, 0));
	if (len > size - start)
		len = size - start;
	str = malloc((len + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start] != 0)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size_pre;
	size_t	size_suf;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	size_pre = ft_strlen(s1);
	size_suf = ft_strlen(s2);
	str = malloc((size_pre + size_suf + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

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
