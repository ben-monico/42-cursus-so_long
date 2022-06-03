/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basehex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:16:40 by bcarreir          #+#    #+#             */
/*   Updated: 2022/03/14 18:21:45 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_convert(unsigned int long n, char *s)
{	
	int	cc;

	cc = 0;
	if (n >= 16)
	{
		cc += ft_convert(n / 16, s);
		cc += ft_convert(n % 16, s);
	}
	else
		cc += ft_putchar(s[n % 16]);
	return (cc);
}

int	ft_puthex(unsigned int n, char c)
{
	int	cc;

	if (c == 'x')
		cc = ft_convert(n, "0123456789abcdef");
	else
		cc = ft_convert(n, "0123456789ABCDEF");
	return (cc);
}

int	ft_putptr(unsigned int long uil)
{
	int	cc;

	cc = ft_convert(uil, "0123456789abcdef");
	return (cc);
}
