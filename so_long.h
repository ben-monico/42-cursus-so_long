/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:51:05 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/26 17:48:07 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "gnl.h"
# include "mlx.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_data {
	void	*img;
	char	*addr;
	int 	bpp;
	int 	line_len;
	int 	endian;
}	t_data;

typedef struct s_map {
	int	hei;
	int wid;
}	t_map;

typedef struct s_sprite {
	void	*player;
	void	*wall;
	void	*land;
	void	*collect;
	void	*exit;
}	t_sprite;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		*mapstr;
	t_map		*map;
	t_sprite	*sprite;
}	t_game;

int		ft_error_check(char *str, t_map *map);
int		move_up(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		move_down(t_game *game);
char	*ft_parse_map(char *av, t_map *map);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif
