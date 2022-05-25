/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:47:30 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/25 17:40:36 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	define_xpm()

int	exit_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);	
	exit(1);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_win(game);
	if (key == KEY_W)
		exit_win(game);
	if (key == KEY_A)
		exit_win(game);
	if (key == KEY_S)
		exit_win(game);
	if (key == KEY_D)
		exit_win(game);
	return (0);
}

int	init_all(t_game *game, char **av)
{
    game->map = malloc(sizeof(t_map));
    if (!game->map)
	{
		free(game);
        return (0);
	}
    game->map->hei = 0;
    game->map->wid = 0;
    game->mapstr = ft_parse_map(av[1], game->map);
    if (!game->mapstr)
	{
		free(game);
		free(game->map);
        return (0);
	}
    game->sprite = malloc(sizeof(t_sprite));
    if (!game->sprite)
    {
		free(game);
        free(game->map);
        return (0);
    }
	return (1);
}

int	main(int ac, char **av)
{
    t_game game;

//    void    *imge;
//    char    *path = "./download.png";
//    int     imgw;
//    int     imgh;
//	t_data	screen;

    if (ac != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
	if (!init_all(&game, av))
		return (1);
    game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map->hei * 64, game.map->wid * 64, "so_long_suckers");
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, press_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, exit_win, &game);
	mlx_loop(game.mlx);

	
//    imge = mlx_xpm_file_to_image(mlx, "./pot.xpm", &imgw, &imgh);
//	screen.img = mlx_new_image(mlx, 1920, 1080);
//	screen.addr = mlx_get_data_addr(screen.img, &screen.bpp, &screen.line_len, &screen.endian);
//	mlx_put_image_to_window(mlx, win, screen.img, 0, 0);
//	mlx_put_image_to_window(mlx, win, imge, 0, 0);
//	mlx_put_image_to_window(mlx, win, imge, 24, 0);
	return (0);
}