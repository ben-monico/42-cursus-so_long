/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:25:52 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/04 18:30:39 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	assign_counter_nb(t_g *g, char c)
{
	int	x;
	int	y;

	if (c == '0')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/0.xpm", &x, &y);
	else if (c == '1')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/1.xpm", &x, &y);
	else if (c == '2')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/2.xpm", &x, &y);
	else if (c == '3')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/3.xpm", &x, &y);
	else if (c == '4')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/4.xpm", &x, &y);
	else if (c == '5')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/5.xpm", &x, &y);
	else if (c == '6')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/6.xpm", &x, &y);
	else if (c == '7')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/7.xpm", &x, &y);
	else if (c == '8')
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/8.xpm", &x, &y);
	else
		g->spt->counter1 = mlx_xpm_file_to_image(g->mlx, "./s/9.xpm", &x, &y);
	return ;
}

static void	clear_counter_space(t_g *g)
{
	int	i;
	int	w;

	w = 0;
	i = -1;
	while (g->mapstr[++i] && g->mapstr[i] != '\n')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->spt->land, w, 0);
		w += 64;
	}
	w = 0;
	i = -1;
	while (g->mapstr[++i] && g->mapstr[i] != '\n')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->spt->wall, w, 0);
		w += 64;
	}
}

void	update_counter(t_g *g)
{
	char	*counter;
	int		i;
	int		w;
	int		h;

	counter = ft_itoa(g->steps);
	if (!counter)
		return ;
	clear_counter_space(g);
	i = 0;
	w = 12;
	h = 4;
	while (counter[i])
	{
		assign_counter_nb(g, counter[i]);
		if (counter[i] > '5')
			h = -4;
		mlx_put_image_to_window(g->mlx, g->win, g->spt->counter1, w, h);
		w += 48;
		i++;
	}
	free(counter);
	return ;
}
