/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:47:30 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/26 17:53:25 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	create_win(t_game *game)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	w = 0;
	h = 0;
	while(game->mapstr[i])
	{
		if (game->mapstr[i] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->player, w, h);
		else if (game->mapstr[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->collect, w, h);
		else if (game->mapstr[i] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->land, w, h);
		else if (game->mapstr[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->wall, w, h);
		else if (game->mapstr[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->exit, w, h);
		w += 64;
		if (game->mapstr[i] == '\n')
		{
			h += 64;
			w = 0;
		}
		i++;
	}
	return (0);
}

int	exit_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_win(game);
	if (key == KEY_W)
		move_up(game);
	else if (key == KEY_A)
		move_left(game);
	else if (key == KEY_S)
		move_down(game);
	else if (key == KEY_D)
		move_right(game);
	create_win(game);	
	return (0);
}

int	init_all(t_game *game, char **av)
{
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (0);
    game->map->hei = 0;
    game->map->wid = 0;
    game->mapstr = ft_parse_map(av[1], game->map);
    if (!game->mapstr)
	{
		free(game->map);
        return (0);
	}
    game->sprite = malloc(sizeof(t_sprite));
    if (!game->sprite)
    {
        free(game->map);
        return (0);
    }
	// define_xpm(game);
	return (1);
}

int	main(int ac, char **av)
{
    t_game game;
	int	x;
	int	y;

    if (ac != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
	if (!init_all(&game, av))
		return (1);
    game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map->wid * 64, (game.map->hei + 1) * 64, "so_long_suckers");
	game.sprite->player = mlx_xpm_file_to_image(game.mlx, "./i_player.xpm", &x, &y);
	game.sprite->collect = mlx_xpm_file_to_image(game.mlx, "./i_fish.xpm", &x, &y);
	game.sprite->land = mlx_xpm_file_to_image(game.mlx, "./i_land.xpm", &x, &y);
	game.sprite->wall = mlx_xpm_file_to_image(game.mlx, "./i_wall.xpm", &x, &y);
	game.sprite->exit = mlx_xpm_file_to_image(game.mlx, "./i_exit0.xpm", &x, &y);
	create_win(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, press_key, &game);
	// mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, exit_win, &game);
	mlx_loop(game.mlx);


//    void    *imge;
//    char    *path = "./download.png";
//    int     imgw;
//    int     imgh;
//	t_data	screen;
	
//    imge = mlx_xpm_file_to_image(mlx, "./pot.xpm", &imgw, &imgh);
//	screen.img = mlx_new_image(mlx, 1920, 1080);
//	screen.addr = mlx_get_data_addr(screen.img, &screen.bpp, &screen.line_len, &screen.endian);
//	mlx_put_image_to_window(mlx, win, screen.img, 0, 0);
//	mlx_put_image_to_window(mlx, win, imge, 0, 0);
//	mlx_put_image_to_window(mlx, win, imge, 24, 0);
	return (0);
}