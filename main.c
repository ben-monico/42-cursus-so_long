/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:47:30 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/14 15:06:30 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_win(t_g **g)
{
	mlx_destroy_window((*g)->mlx, (*g)->win);
	free((*g)->map);
	free((*g)->spt);
	free((*g)->mlx);
	system("leaks -- so_long");
	exit(1);
}

int	create_win(t_g *g)
{
	int	i;
	int	w;
	int	h;

	i = -1;
	w = 0;
	h = 0;
	while (g->mapstr[++i])
	{
		mlx_put_image_to_window(g->mlx, g->win, g->spt->land, w, h);
		put_image(g, g->mapstr[i], w, h);
		w += 64;
		if (g->mapstr[i] == '\n')
		{
			h += 64;
			w = 0;
		}
	}
	update_counter(g);
	return (0);
}

int	assign_xpm(t_g *g)
{
	int	x;
	int	y;

	g->spt->player = mlx_xpm_file_to_image(g->mlx, "./s/player.xpm", &x, &y);
	g->spt->collect = mlx_xpm_file_to_image(g->mlx, "./s/shrimp.xpm", &x, &y);
	g->spt->land = mlx_xpm_file_to_image(g->mlx, "./s/floor.xpm", &x, &y);
	g->spt->wall = mlx_xpm_file_to_image(g->mlx, "./s/wall.xpm", &x, &y);
	g->spt->exit = mlx_xpm_file_to_image(g->mlx, "./s/iglooBW.xpm", &x, &y);
	g->spt->patrol = mlx_xpm_file_to_image(g->mlx, "./s/patrol.xpm", &x, &y);
	if (!g->spt->player || !g->spt->collect || !g->spt->land
		|| !g->spt->wall || !g->spt->exit)
	{
		ft_printf("Error\nInvalid or missing .xpm file\n");
		return (0);
	}
	return (1);
}

int	init_all(t_g *g, char **av)
{
	g->map = malloc(sizeof(t_map));
	if (!g->map)
		return (0);
	g->map->h = 0;
	g->map->w = 0;
	g->map->on_exit = 0;
	g->isopen = 0;
	g->mapstr = ft_parse_map(av[1], g);
	if (!g->mapstr)
	{
		free(g->map);
		return (0);
	}
	g->spt = malloc(sizeof(t_spt));
	if (!g->spt)
	{
		free(g->map);
		return (0);
	}
	g->steps = 0;
	g->over = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_g		g;
	char	*ext;

	if (ac != 2)
	{
		write(1, "Error\nInvalid arg count\n", 25);
		return (1);
	}
	ext = ft_strrchr(av[1], '.');
	if (!ext || strcmp(ext, ".ber") || !init_all(&g, av))
	{
		write(1, "Error\nInvalid or missing map file\n", 35);
		return (1);
	}
	g.mlx = mlx_init();
	if (!assign_xpm(&g))
		return (1);
	g.win = mlx_new_window(g.mlx, g.map->w * 64,
			(g.map->h + 1) * 64, "so_long_suckers");
	create_win(&g);
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, press_key, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 0, exit_win, &g);
	mlx_loop(g.mlx);
	return (0);
}
