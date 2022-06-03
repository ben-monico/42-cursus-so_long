/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:12:24 by bcarreir          #+#    #+#             */
/*   Updated: 2022/03/14 18:23:17 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_checkspec(const char *str, int i, va_list *ap)
{
	int	cc;

	cc = 0;
	if (str[i] == 'c')
		cc += ft_putchar((char)va_arg(*ap, int));
	else if (str[i] == 's')
		cc += ft_putstr(va_arg(*ap, char *));
	else if (str[i] == 'p')
	{
		cc += ft_putstr("0x");
		cc += ft_putptr(va_arg(*ap, unsigned int long));
	}
	else if (str[i] == 'd' || str[i] == 'i')
		cc += ft_putint(va_arg(*ap, int));
	else if (str[i] == 'u')
		cc += ft_putuint(va_arg(*ap, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		cc += ft_puthex(va_arg(*ap, unsigned int), str[i]);
	else if (str[i] == '%')
		cc += ft_putchar('%');
	return (cc);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cc;
	va_list	args;

	i = 0;
	cc = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cc += ft_checkspec(str, i, &args);
		}
		else
			cc += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (cc);
}

// int main(void)
// {
// 	printf("%d\n", ft_printf("%x%X\n", 11, -11));
// 	printf("%d\n", printf("%x%X\n", 11, -11));
// }