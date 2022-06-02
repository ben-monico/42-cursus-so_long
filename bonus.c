/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:57:46 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/02 18:41:06 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*patrol_handler(char *str)
{
	int	p;
	int	i;
	int	r;

	p = 0;
	i = -1;
	while (str[++i])
		if (str[i] == 'C')
			p += 2;
	while (p)
	{
		i = -1;
		while (str[++i])
		{
			if (p == 0)
				break ;
			if (str[i] == '0')
			{
				r = rand() % 75;
				if (r == 1)
				{
					p--;
					str[i] = 'F';
				}
			}
		}
	}
	return (str);
}
