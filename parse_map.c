#include "so_long.h"

static char	*ft_read_map_to_str(char *av)
{
	char	*line;
	char	*mapstr;
	char	*s1;
	int		fd;

	fd = open(av, O_RDONLY);
	mapstr = NULL;
	line = NULL;
	s1 = NULL;
	while ((line = get_next_line(fd)))
	{
		s1 = mapstr;
		mapstr = ft_strjoin(s1, line);
		if (!mapstr)
		{
			free(line);
			return (NULL);
		}
		free(line);
		free(s1);
	}
	return(mapstr);
}

char 	*ft_parse_map(char *av, t_game *game)
{
	char	*mapstr;
	int		isplayer;
	int		i;
	
	isplayer = 0;
	mapstr = ft_read_map_to_str(av);
	if (!mapstr)
		return (NULL);
	if (ft_error_check(mapstr, game->map))
		return (NULL);
	i = 0;
	while (mapstr[i++])
	{
		if (mapstr[i] == 'P' && isplayer == 1)
			mapstr[i] = '0';
		if (mapstr[i] == 'P' && isplayer == 0)
			isplayer = 1;
		if (mapstr[i] == 'E')
			game->map->on_exit = 0;
	}
	return (mapstr);
}