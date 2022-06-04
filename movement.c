/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:50:37 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/04 18:33:12 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_condition(t_g *g)
{
	int	x;
	int	y;
	int	i;

	if (!ft_strchr(g->mapstr, 'C') && g->isopen == 0)
	{
		g->spt->exit = mlx_xpm_file_to_image(g->mlx,
				"./s/igloo.xpm", &x, &y);
		g->isopen = 1;
		i = 0;
		while (g->mapstr[i++])
			if (g->mapstr[i] == 'E')
				update_win(g, i, i);
	}
	if (g->map->on_exit == 1)
	{
		ft_printf("Game Won in %d steps. Press 'Esc' to exit.\n", g->steps);
		return (0);
	}
	else if (g->over == 1)
	{
		ft_printf("Game Over! Press 'Esc' to exit.\n", g->steps);
		return (0);
	}
	return (1);
}

int	press_key(int key, t_g *g)
{
	int	cur;

	cur = g->steps;
	if (key == KEY_ESC)
		exit_win(g);
	if (!move_condition(g))
		return (0);
	if (key == KEY_W)
		g->steps += move_up(g);
	else if (key == KEY_A)
		g->steps += move_left(g);
	else if (key == KEY_S)
		g->steps += move_down(g);
	else if (key == KEY_D)
		g->steps += move_right(g);
	if (!move_condition(g))
		return (0);
	if (cur < g->steps)
	{
		ft_printf("Steps: %d\n", g->steps);
		update_counter(g);
	}
	return (0);
}
