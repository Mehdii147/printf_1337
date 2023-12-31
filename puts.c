/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:34:47 by ehafiane          #+#    #+#             */
/*   Updated: 2023/11/30 15:24:59 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int		cnt;
	long	n1 ;

	n1 = nb;
	cnt = 0;
	if (n1 < 0) 
	{
		cnt += ft_putchar('-');
		n1 *= -1;
	}
	if (n1 >= 10) 
	{
		cnt += ft_putnbr(n1 / 10);
		n1 = n1 % 10;
	}
	if (n1 < 10)
		cnt += ft_putchar(n1 + 48);
	return (cnt);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
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
