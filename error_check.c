/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:23:10 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/24 19:25:51 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_must_have(char *str)
{
	if (!ft_strchr(str, 'P'))
	{
		write(1, "Error\nNo Starting Position\n", 28);
		return (0);
	}
	if (!ft_strchr(str, 'C'))
	{
		write(1, "Error\nNo Collectibles\n", 23);
		return (0);
	}
	if (!ft_strchr(str, 'E'))
	{
		write(1, "Error\nNo Exit\n", 15);
		return (0);
	}
	return (1);
}

static int	ft_is_rectangle(char *str, t_map *map)
{
	int	i;
	int	j;

	while (str[map->wid] && str[map->wid] != '\n')
		map->wid++;
	i = 0;
	j = -1;
	while (str[++j])
	{
		if (str[j] == '\n' && i != map->wid)
			break ;
		else if (str[j] == '\n' && i == map->wid)
		{
			i = 0;
			map->hei++;
		}
		if (str[j] != '\n')
			i++;
	}
	if (i != map->wid || map->wid < 2)
		write(1, "Error\nMap is not rectangular\n", 30);
	return (i == map->wid);
}

static int	ft_wall_surround(char *str, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		if (str[k] != '\n' && (j == 0 || j == map->hei || i == 0 || i == map->wid) && str[k] != '1')
		{
			write(1, "Error\nMap must be surrounded by walls\n", 41);
			return (0);
		}
		if (str[k] == '\n')
		{
			j++;
			i = 0;
		}
		else
			i++;
		k++;
	}
	return (1);
}

int	ft_error_check(char *str, t_map *map)
{
	char	*letters;

	letters  = "01PCE\n";
	if (!ft_must_have(str) || !ft_is_rectangle(str, map))
		return (1);
	if (!ft_wall_surround(str, map))
		return (1);
	while (*str++)
	{
		if (!ft_strchr(letters, *str))
		{
			write(1, "Error\nInvalid character input\n", 31);
			return (1);
		}
	}
	return (0);
}
