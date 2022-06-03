/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphanum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:17:46 by bcarreir          #+#    #+#             */
/*   Updated: 2022/03/14 18:27:11 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putint(int n)
{
	long	nb;
	int		cc;

	cc = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		cc += ft_putchar('-');
	}
	if (nb >= 10)
	{
		cc += ft_putint(nb / 10);
		cc += ft_putchar("0123456789"[nb % 10]);
	}
	else
		cc += ft_putchar("0123456789"[nb % 10]);
	return (cc);
}

int	ft_putuint(unsigned int long n)
{
	int	cc;

	cc = 0;
	if (n >= 10)
	{
		cc += ft_putuint(n / 10);
		cc += ft_putchar("0123456789"[n % 10]);
	}
	else
		cc += ft_putchar("0123456789"[n % 10]);
	return (cc);
}
