/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:47:30 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/03 19:46:27 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

int move_condition(t_game *game)
{
	int	x;
	int	y;

	if (!ft_strchr(game->mapstr, 'C'))
	{
		game->sprite->exit = mlx_xpm_file_to_image(game->mlx, "./s/igloo.xpm", &x, &y);
		game->isopen = 1;	
	}
	if (game->map->on_exit == 1)
	{
		ft_printf("Success! You finished the game in %d steps. Press 'Esc' to exit.\n", game->steps);
		create_win(game);
		return (0);
	}
	else if (game->over == 1)
	{
		game->sprite->player = mlx_xpm_file_to_image(game->mlx, "./s/playerdead.xpm", &x, &y);
		ft_printf("Momma shoulda told you not to mess with frogs. Press 'Esc' to exit.\n", game->steps);
		create_win(game);
		return (0);
	}
	create_win(game);
	return (1);
}

int	press_key(int key, t_game *game)
{
	int	cur;

	cur = game->steps;
	if (key == KEY_ESC)
		exit_win(game);
	if (!move_condition(game))
		return (0);
	if (key == KEY_W)
		game->steps += move_up(game);
	else if (key == KEY_A)
		game->steps += move_left(game);
	else if (key == KEY_S)
		game->steps += move_down(game);
	else if (key == KEY_D)
		game->steps += move_right(game);
	if (!move_condition(game))
		return (0);
	create_win(game);
	if (cur < game->steps)
		ft_printf("Steps: %d\n", game->steps);
	return (0);
}

int	assign_xpm(t_game *game)
{
	int	x;
	int	y;

	game->sprite->player = mlx_xpm_file_to_image(game->mlx, "./s/player.xpm", &x, &y);
	game->sprite->collect = mlx_xpm_file_to_image(game->mlx, "./s/shrimp.xpm", &x, &y);
	game->sprite->land = mlx_xpm_file_to_image(game->mlx, "./s/floor.xpm", &x, &y);
	game->sprite->wall = mlx_xpm_file_to_image(game->mlx, "./s/wall.xpm", &x, &y);
	game->sprite->exit = mlx_xpm_file_to_image(game->mlx, "./s/iglooBW.xpm", &x, &y);
	game->sprite->patrol = mlx_xpm_file_to_image(game->mlx, "./s/patrol.xpm", &x, &y);
	if (!game->sprite->player  || !game->sprite->collect || !game->sprite->land ||
		!game->sprite->wall || !game->sprite->exit)
		{
			ft_printf("Error\nInvalid or missing .xpm file\n");
			return (0);
		}
	return (1);
}

int	init_all(t_game *game, char **av)
{
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (0);
    game->map->hei = 0;
    game->map->wid = 0;
	game->map->on_exit = 0;
	game->isopen = 0;
    game->mapstr = ft_parse_map(av[1], game);
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
	game->steps = 0;
	game->over = 0;
	return (1);
}

int	main(int ac, char **av)
{
    t_game	game;
	char	*extension;

    if (ac != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
	extension = ft_strrchr(av[1], '.');
	if (!extension || strcmp(extension, ".ber"))
	{
        write(1, "Error\n", 6);
		return (1);
	}
	if (!init_all(&game, av))
		return (1);
    game.mlx = mlx_init();
	if (!assign_xpm(&game))
		return (1);
	game.win = mlx_new_window(game.mlx, game.map->wid * 64, (game.map->hei + 1) * 64, "so_long_suckers");
	create_win(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, press_key, &game);
	system("leaks -- so_long");
	mlx_loop(game.mlx);
	return (0);
}

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