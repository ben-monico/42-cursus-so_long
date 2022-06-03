/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:17:52 by benmonico         #+#    #+#             */
/*   Updated: 2022/05/25 14:10:02 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_checknlc(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (buffer[i] != '\n');
}

void	ft_update(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buffer[i])
	{
		if (j == -1 && buffer[i] == '\n')
			j = 0;
		else if (j >= 0)
			buffer[j++] = buffer[i];
		buffer[i++] = 0;
	}
}

char	*ft_get_line(char *line, char *buffer)
{
	char	*aux;
	int		i;
	int		j;	

	aux = line;
	i = 0;
	line = malloc(sizeof(char) * ft_strlengnl(buffer) + ft_strlengnl(aux) + 1);
	if (!line)
		return (NULL);
	if (aux)
		i = ft_strcpy(line, aux);
	j = 0;
	while (buffer[j])
	{
		line[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	line [i] = '\0';
	if (aux)
	{
		free(aux);
		aux = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	size_t		ret;
	size_t		i;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	line = NULL;
	i = 1;
	while (i)
	{
		ret = 1;
		if (!buffer[0])
			ret = read(fd, buffer, BUFFER_SIZE);
		i = ft_checknlc(buffer) * ret > 0;
		if (ret > 0)
			line = ft_get_line(line, buffer);
		ft_update(buffer);
	}
	return (line);
}

// #include <fcntl.h>

// int	main ()
// {
//  	int fd;
//  	char *str;	 
// 	fd = open("hello.txt", O_RDONLY);
//  	while (1)
// 	 {
// 		 str = get_next_line(fd);
// 		 printf("%s", str);
// 		 if (!str)
// 		 	break ;
// 	 }
// }