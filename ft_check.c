/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:27:19 by ehafiane          #+#    #+#             */
/*   Updated: 2023/11/29 18:50:05 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list p)
{
	int	size; 

	size = 0;
	if (c == '%')
		size += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(p, int));
	else if (c == 's')
		size += ft_putstr(va_arg(p, char *));
	else if (c == 'c')
		size += ft_putchar(va_arg(p, int));
	else if (c == 'x' || c == 'X')
		size += ft_hexa(va_arg(p, int), c);
	else if (c == 'p')
		size += ft_put_pointer(va_arg(p, size_t));
	else if (c == 'u')
		size += ft_put_unsigned(va_arg(p, size_t));
	else
		size += ft_putchar(c);
	return (size);
}
