/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:48:56 by bcarreir          #+#    #+#             */
/*   Updated: 2022/03/14 18:20:55 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putint(int n);
int		ft_puthex(unsigned int n, char c);
int		ft_putuint(unsigned int long n);
int		ft_putstr(char *s);
int		ft_putptr(unsigned int long uil);
int		ft_printf(const char *str, ...);

#endif