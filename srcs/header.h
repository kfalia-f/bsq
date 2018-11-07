/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:25:22 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 21:11:48 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUF_SIZE 1

char	g_em;
char	g_ob;
char	g_fu;
int		g_len;
int		g_wid;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *s);
int		ft_rdfl(int argc, char **argv, int ***map);
void	ft_rd(int fd, int **map);
void	ft_map(int ***map, char *argv);
void	ft_error(int er);
int		ft_atoi(char *str);
void	ft_alg(int **map);
void	ft_number(int *num, char *str, int *flaq);
int		ft_param(int fd);
void	ft_rd_stdin(int fd, int **map);

#endif
