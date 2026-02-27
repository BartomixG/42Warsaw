/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:20:46 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/02 13:53:29 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line_buffer(int fd, char *left_c)
{
	char	*buf;
	ssize_t	b_read;
	char	*temp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	b_read = 1;
	while ((!left_c || !ft_strchr(left_c, '\n')) && b_read != 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buf);
			free(left_c);
			return (NULL);
		}
		buf[b_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		temp = left_c;
		left_c = ft_strjoin(temp, buf);
		free(temp);
	}
	return (free(buf), left_c);
}

char	*update_memory(char *mem)
{
	int		i;
	int		j;
	char	*new_mem;

	i = 0;
	j = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	if (!mem[i])
	{
		free(mem);
		return (NULL);
	}
	new_mem = malloc(sizeof(char) * (ft_strlen(mem) - i + 1));
	if (!new_mem)
	{
		free(mem);
		return (NULL);
	}
	i++;
	while (mem[i])
		new_mem[j++] = mem[i++];
	new_mem[j] = '\0';
	free(mem);
	return (new_mem);
}

static char	*ft_get_line(char *mem)
{
	int		i;
	char	*line;

	i = 0;
	if (!mem || !mem[i])
		return (NULL);
	while (mem[i] && mem[i] != '\n')
		i++;
	line = ft_substr(mem, 0, ++i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem = fill_line_buffer(fd, mem);
	if (!mem)
		return (NULL);
	line = ft_get_line(mem);
	mem = update_memory(mem);
	return (line);
}
