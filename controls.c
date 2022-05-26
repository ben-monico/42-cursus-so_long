/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:24:31 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/26 17:53:10 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i] == 'P' && game->mapstr[i - game->map->wid - 1] != '1')
	{
		game->mapstr[i - game->map->wid - 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}
int	move_left(t_game *game)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i] == 'P' && game->mapstr[i - 1] != '1')
	{
		game->mapstr[i - 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}
int	move_down(t_game *game)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i] == 'P' && game->mapstr[i + game->map->wid + 1] != '1')
	{
		game->mapstr[i + game->map->wid + 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}
int	move_right(t_game *game)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i] == 'P' && game->mapstr[i + 1] != '1')
	{
		game->mapstr[i + 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}