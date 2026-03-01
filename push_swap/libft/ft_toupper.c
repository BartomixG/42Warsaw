/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:02:03 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/13 18:03:37 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}

// #include <stdio.h>
// int main() {
//     char c1 = 'a';
//     char c2 = 'Z';
//     char c3 = '5';

//     printf("%c -> %c\n", c1, ft_toupper(c1));
//     printf("%c -> %c\n", c2, ft_toupper(c2));
//     printf("%c -> %c\n", c3, ft_toupper(c3));

//     return 0;
// }