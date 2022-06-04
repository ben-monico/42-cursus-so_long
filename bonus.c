/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:57:46 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/04 18:17:43 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*patrol_handler(char *str)
{
	int	p;
	int	i;
	int	l;

	p = 0;
	l = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'C')
			p += 2;
		else if (str[i] == '0')
			l++;
	}
	while (p && ft_strchr(str, '0') && l > 3 && l > p)
	{
		i = -1;
		while (p && str[++i])
		{
			if (str[i] == '0' && rand() % 34 == 1 && --p)
				str[i] = 'F';
		}
	}
	return (str);
}
