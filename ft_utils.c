/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:48:18 by ehafiane          #+#    #+#             */
/*   Updated: 2023/11/30 15:24:52 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
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
