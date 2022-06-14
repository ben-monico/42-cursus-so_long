/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:25:57 by bcarreir          #+#    #+#             */
/*   Updated: 2022/06/14 14:37:04 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

char	*get_next_line(int fd);
int		ft_checknlc(char *buffer);
size_t	ft_strlengnl(const char *str);
size_t	ft_strcpy(char *line, char *aux);
void	ft_update(char *buff);
char	*ft_get_line(char *line, char *buff);

#endif