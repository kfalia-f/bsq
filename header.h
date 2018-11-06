/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:25:22 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/06 12:16:42 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUF_SIZE 1

char	q_em;
char	g_ob;
char	g_fu;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *s);
int		ft_rdfl(int argc, char **argv, char ***map);
void	ft_rd(int fd, char **map);
void	ft_map(char ***map, char *argv);
void	ft_error(int er);
int		ft_atoi(char *str);

#endif
