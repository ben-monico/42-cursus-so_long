/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:19:04 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/04 18:45:10 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_wh_put_img(t_g *g, int i)
{
	int	w;
	int	h;
	int	x;

	if (g->mapstr[i] == '1')
		return ;
	x = 0;
	w = 0;
	h = 0;
	while (x < i)
	{
		w += 64;
		if (g->mapstr[x] == '\n')
		{
			h += 64;
			w = 0;
		}
		x++;
	}
	put_image(g, g->mapstr[i], w, h);
}

void	update_win(t_g *g, int i, int j)
{
	get_wh_put_img(g, i);
	get_wh_put_img(g, j);
	return ;
}

void	put_image(t_g *g, char c, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->win, g->spt->land, w, h);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->spt->wall, w, h);
	else if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->spt->player, w, h);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->spt->collect, w, h);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->spt->exit, w, h);
	else if (c == 'F')
		mlx_put_image_to_window(g->mlx, g->win, g->spt->patrol, w, h);
	return ;
}
