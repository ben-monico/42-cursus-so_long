/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:57:06 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/02 18:57:14 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != (unsigned char)c)
		i--;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

static void	ft_itochar(int n, char *s, int len)
{
	long	nb;
	int		i;

	nb = n;
	i = len;
	if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
	}
	s[i] = '\0';
	i--;
	while (nb >= 10)
	{
		s[i] = "0123456789"[nb % 10];
		nb /= 10;
		i--;
	}
	s[i] = "0123456789"[nb % 10];
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*s;

	len = 1;
	nb = n;
	if (n < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (s);
	ft_itochar(n, s, len);
	return (s);
}
