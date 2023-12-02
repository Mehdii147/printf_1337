/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:38:37 by ehafiane          #+#    #+#             */
/*   Updated: 2023/12/02 12:23:14 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		size;
	int		i; 

	va_start(p, s);
	size = 0;
	i = 0;
	if (write(1, "", 0))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			size += ft_check(s[i + 1], p);
			i++;
		}
		else 
			size += ft_putchar(s[i]);
		if (s[i])
			i++;
	}
	va_end(p);
	return (size);
}
