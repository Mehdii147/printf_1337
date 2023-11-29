/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:48:18 by ehafiane          #+#    #+#             */
/*   Updated: 2023/11/29 18:51:01 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int nb, const char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb >= 16)
	{
		ft_hexa(nb / 16, format);
		ft_hexa(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else if (format == 'x')
			ft_putchar(nb - 10 + 'a');
		else if (format == 'X')
			ft_putchar(nb - 10 + 'A');
	}
	return (ft_hex_len(nb));
}

int	hex_point_len(size_t num)
{
	int	len;

	len = 0;
	if (num < 0)
		num *= -1;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	hex_point(size_t nb, const char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb >= 16)
	{
		hex_point(nb / 16, format);
		hex_point(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else if (format == 'x')
			ft_putchar(nb - 10 + 'a');
		else if (format == 'X')
			ft_putchar(nb - 10 + 'A');
	}
	return (hex_point_len(nb));
}

int	ft_put_pointer(size_t nb)
{
	return (ft_putstr("0x") + hex_point(nb, 'x'));
}

int	ft_put_unsigned(unsigned int nb)
{
	int		cnt;
	long	n1 ;

	n1 = nb;
	cnt = 0;
	if (n1 >= 10) 
	{
		cnt += ft_putnbr(n1 / 10);
		n1 = n1 % 10;
	}
	if (n1 < 10)
		cnt += ft_putchar(n1 + 48);
	return (cnt);
}
