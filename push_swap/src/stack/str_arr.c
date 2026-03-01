/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:32:07 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/26 21:54:54 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_argcgen(char **argv)
{
	int	argc;
	int	i;

	if (!argv)
		return (-1);
	argc = 0;
	i = 0;
	while (argv[i])
	{
		argc++;
		i++;
	}
	return (argc);
}

void	ft_freesplit(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
