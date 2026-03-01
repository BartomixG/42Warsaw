/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:03:33 by bgorski           #+#    #+#             */
/*   Updated: 2025/09/30 01:53:46 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

// #include <stdio.h>
// int main(void)
// {
//     char c1 = 'a';
//     char c2 = 'Z';
//     char c3 = '5';
//     printf("%c -> %c\n", c1, ft_tolower(c1)); // a -> A
//     printf("%c -> %c\n", c2, ft_tolower(c2)); // Z -> z
//     printf("%c -> %c\n", c3, ft_tolower(c3)); // 5 -> 5 (unchanged)
//     return 0;
// }
