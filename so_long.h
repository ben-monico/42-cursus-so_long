/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:51:05 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/14 14:48:10 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "gnl.h"
# include "mlx.h"
# include "libftprintf.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_map {
	int	h;
	int w;
	int	on_exit;
}	t_map;

typedef struct s_spt {
	void	*player;
	void	*wall;
	void	*land;
	void	*collect;
	void	*exit;
	void	*patrol;
	void	*counter1;
}	t_spt;

typedef struct s_g {
	void		*mlx;
	void		*win;
	char		*mapstr;
	t_map		*map;
	t_spt	*spt;
	int			steps;
	int			isopen;
	int			over;
}	t_g;

int		create_win(t_g *g);
int		ft_error_check(char *str, t_map *map);
int		exit_win(t_g **g);
char	*ft_itoa(int n);
int		move_up(t_g *g);
int		move_left(t_g *g);
int		move_right(t_g *g);
int		move_down(t_g *g);
char	*ft_parse_map(char *av, t_g *g);
char	*patrol_handler(char *str);
int		press_key(int key, t_g *g);
void	put_image(t_g *g, char c, int w, int h);
int		spt_collider(char c, t_g *g);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	update_counter(t_g *g);
void	update_win(t_g *g, int i, int j);

#endif
