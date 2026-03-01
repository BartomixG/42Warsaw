/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:23:19 by bgorski           #+#    #+#             */
/*   Updated: 2025/10/31 20:36:42 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_print_char(va_list arg);
int		ft_print_dec(va_list arg);
int		ft_print_un_dec(va_list arg);
int		ft_print_hex_low(va_list arg);
int		ft_print_hex_uppr(va_list arg);
int		ft_print_percnt(void);
int		ft_print_ptr(va_list arg);
int		ft_print_str(va_list arg);
#endif
