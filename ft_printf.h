/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:46:37 by ehafiane          #+#    #+#             */
/*   Updated: 2023/11/29 18:51:39 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_check(char c, va_list p);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_hex_len(unsigned int num);
int	ft_hexa(unsigned int nb, char format);
int	hex_point(size_t nb, const char format);
int	ft_printf(const char *s, ...);
int	ft_put_pointer(size_t nb);
int	ft_put_unsigned(unsigned int nb);

#endif