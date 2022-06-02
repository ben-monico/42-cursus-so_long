/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:24:31 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/02 18:24:13 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	game->sprite->player = mlx_xpm_file_to_image(game->mlx, "./s/playerback.xpm", &x, &y);
	if (!sprite_collider(game->mapstr[i - game->map->wid - 1], game))
		return (0);
	game->mapstr[i - game->map->wid - 1] = 'P';
	game->mapstr[i] = '0';
	return (1);
}
int	move_left(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	game->sprite->player = mlx_xpm_file_to_image(game->mlx, "./s/playerleft.xpm", &x, &y);
	if (!sprite_collider(game->mapstr[i - 1], game))
		return (0);
	game->mapstr[i - 1] = 'P';
	game->mapstr[i] = '0';
	return (1);
}
int	move_down(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	game->sprite->player = mlx_xpm_file_to_image(game->mlx, "./s/player.xpm", &x, &y);
	if (!sprite_collider(game->mapstr[i + game->map->wid + 1], game))
		return (0);
	game->mapstr[i + game->map->wid + 1] = 'P';
	game->mapstr[i] = '0';
	return (1);
}
int	move_right(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while(game->mapstr[i] && game->mapstr[i] != 'P')
		i++;
	game->sprite->player = mlx_xpm_file_to_image(game->mlx, "./s/playerright.xpm", &x, &y);
	if (!sprite_collider(game->mapstr[i + 1], game))
		return (0);
	game->mapstr[i + 1] = 'P';
	game->mapstr[i] = '0';
	return (1);
}

int	sprite_collider(char c, t_game *game)
{
	if (c == 'E' && game->isopen == 0)
		return (0);
	if (c == 'F')
	{
		game->over = 1;
		return (0);
	}
	if (c == 'E' && game->isopen == 1)
	{
		game->map->on_exit = 1;
		return (1);
	}
	else if (c != '1')
		return (1);
	return (0);
}