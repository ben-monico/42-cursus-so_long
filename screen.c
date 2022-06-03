/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:19:04 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/03 19:54:19 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	assign_counter_nb(t_game *game, char c)
{
	int	x;
	int	y;

	if (c == '0')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/0.xpm", &x, &y);
	else if (c == '1')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/1.xpm", &x, &y);
	else if (c == '2')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/2.xpm", &x, &y);
	else if (c == '3')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/3.xpm", &x, &y);
	else if (c == '4')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/4.xpm", &x, &y);
	else if (c == '5')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/5.xpm", &x, &y);
	else if (c == '6')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/6.xpm", &x, &y);
	else if (c == '7')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/7.xpm", &x, &y);
	else if (c == '8')
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/8.xpm", &x, &y);
	else
		game->sprite->counter1 = mlx_xpm_file_to_image(game->mlx, "./s/9.xpm", &x, &y);
	return ;
}

static void	update_counter(t_game *game)
{
	char	*counter;
	int		i;
	int		w;
	int		h;

	counter = ft_itoa(game->steps);
	if (!counter)
		return ;
	i = 0;
	w = 12;
	h = 4;
		while (counter[i])
		{
			assign_counter_nb(game, counter[i]);
			if (counter[i] > '5')
				h = -4;
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->counter1, w, h);
			w += 48;
			i++;
	}
	free(counter);
	return ;
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
		mlx_put_image_to_window(game->mlx, game->win, game->sprite->land, w, h);
		if (game->mapstr[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->wall, w, h);
		else if (game->mapstr[i] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->player, w, h);
		else if (game->mapstr[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->collect, w, h);
		else if (game->mapstr[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->exit, w, h);
		else if (game->mapstr[i] == 'F')
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->patrol, w, h);
		w += 64;
		if (game->mapstr[i] == '\n')
		{
			h += 64;
			w = 0;
		}
		i++;
	}
	update_counter(game);
	return (0);
}
