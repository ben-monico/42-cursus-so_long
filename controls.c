/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:24:31 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/01 18:16:36 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game, int open)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i - game->map->wid - 1] == 'E' && open == 0)
		return (0);
	if (game->mapstr[i - game->map->wid - 1] == 'E' && open == 1)
		game->map->on_exit = 1;
	if (game->mapstr[i] == 'P' && game->mapstr[i - game->map->wid - 1] != '1')
	{
		game->mapstr[i - game->map->wid - 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}
int	move_left(t_game *game, int open)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i - 1] == 'E' && open == 0)
		return (0);
	if (game->mapstr[i - 1] == 'E' && open == 1)
		game->map->on_exit = 1;
	if (game->mapstr[i] == 'P' && game->mapstr[i - 1] != '1')
	{
		game->mapstr[i - 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}
int	move_down(t_game *game, int open)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i + game->map->wid + 1] == 'E' && open == 0)
		return (0);
	if (game->mapstr[i + game->map->wid + 1] == 'E' && open == 1)
		game->map->on_exit = 1;
	if (game->mapstr[i] == 'P' && game->mapstr[i + game->map->wid + 1] != '1')
	{
		game->mapstr[i + game->map->wid + 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}
int	move_right(t_game *game, int open)
{
	int	i;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	if (game->mapstr[i + 1] == 'E' && open == 0)
		return (0);
	if (game->mapstr[i + 1] == 'E' && open == 1)
		game->map->on_exit = 1;
	if (game->mapstr[i] == 'P' && game->mapstr[i + 1] != '1')
	{
		game->mapstr[i + 1] = 'P';
		game->mapstr[i] = '0';
		return (1);
	}
	return (0);
}