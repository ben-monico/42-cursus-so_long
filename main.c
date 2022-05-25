/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:47:30 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/24 19:22:12 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
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
    game.map = (t_map *)malloc(sizeof(t_map));
    if (!game.map)
        return (1);
    game.map->hei = 0;
    game.map->wid = 0;
    game.mapstr = ft_parse_map(av[1], game.map);
    if (!game.mapstr)
        return (1);
    game.sprite = malloc(sizeof(t_sprite));
    if (!game.sprite)
    {
        free(game.map);
        return (1);
    }
    game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 900, 900, "so_long_suckers");
	game.mlx = mlx_init();  
//    imge = mlx_xpm_file_to_image(mlx, "./pot.xpm", &imgw, &imgh);
//	screen.img = mlx_new_image(mlx, 1920, 1080);
//	screen.addr = mlx_get_data_addr(screen.img, &screen.bpp, &screen.line_len, &screen.endian);
//	mlx_put_image_to_window(mlx, win, screen.img, 0, 0);
//	mlx_put_image_to_window(mlx, win, imge, 0, 0);
//	mlx_put_image_to_window(mlx, win, imge, 24, 0);
	mlx_loop(game.mlx);
	return (0);
}