/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:24:31 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/04 18:34:15 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_g *g)
{
	int	i;
	int	x;
	int	y;
	int	s;

	s = 0;
	i = 0;
	while (g->mapstr[i] && g->mapstr[i] != 'P')
		i++;
	g->spt->player = mlx_xpm_file_to_image(g->mlx,
			"./s/playerback.xpm", &x, &y);
	if (spt_collider(g->mapstr[i - g->map->w - 1], g))
	{
		g->mapstr[i - g->map->w - 1] = 'P';
		g->mapstr[i] = '0';
		s = 1;
	}
	update_win(g, i, i - g->map->w - 1);
	return (s);
}

int	move_left(t_g *g)
{
	int	i;
	int	x;
	int	y;
	int	s;

	i = 0;
	s = 0;
	while (g->mapstr[i] && g->mapstr[i] != 'P')
		i++;
	g->spt->player = mlx_xpm_file_to_image(g->mlx,
			"./s/playerleft.xpm", &x, &y);
	if (spt_collider(g->mapstr[i - 1], g))
	{
		g->mapstr[i - 1] = 'P';
		g->mapstr[i] = '0';
		s = 1;
	}
	update_win(g, i, i -1);
	return (s);
}

int	move_down(t_g *g)
{
	int	i;
	int	x;
	int	y;
	int	s;

	i = 0;
	s = 0;
	while (g->mapstr[i] && g->mapstr[i] != 'P')
		i++;
	g->spt->player = mlx_xpm_file_to_image(g->mlx,
			"./s/player.xpm", &x, &y);
	if (spt_collider(g->mapstr[i + g->map->w + 1], g))
	{
		g->mapstr[i + g->map->w + 1] = 'P';
		g->mapstr[i] = '0';
		s = 1;
	}
	update_win(g, i, i + g->map->w + 1);
	return (s);
}

int	move_right(t_g *g)
{
	int	i;
	int	x;
	int	y;
	int	s;

	i = 0;
	s = 0;
	while (g->mapstr[i] && g->mapstr[i] != 'P')
		i++;
	g->spt->player = mlx_xpm_file_to_image(g->mlx,
			"./s/playerright.xpm", &x, &y);
	if (spt_collider(g->mapstr[i + 1], g))
	{
		g->mapstr[i + 1] = 'P';
		g->mapstr[i] = '0';
		s = 1;
	}
	update_win(g, i, i + 1);
	return (s);
}

int	spt_collider(char c, t_g *g)
{
	int	x;
	int	y;

	if (c == 'E' && g->isopen == 0)
		return (0);
	if (c == 'F')
	{
		g->over = 1;
		g->spt->player = mlx_xpm_file_to_image(g->mlx,
				"./s/playerdead.xpm", &x, &y);
		return (0);
	}
	if (c == 'E' && g->isopen == 1)
	{
		g->map->on_exit = 1;
		return (1);
	}
	else if (c != '1')
		return (1);
	return (0);
}
