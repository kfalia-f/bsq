/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:51:46 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 20:54:51 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_map_std(int ***map, int f)
{
	char	sym;
	int		i;

	sym = '0';
	g_wid = 0;
	f = ft_param(f);
	while (sym != '\n')
	{
		read(f, &sym, 1);
		g_wid++;
	}
	*map = (int **)malloc(g_len * sizeof(int *));
	if (!map)
		ft_error(4);
	i = g_len - 1;
	while (i >= 0)
	{
		(*map)[i] = (int *)malloc(g_wid * sizeof(int));
		if (!(*map))
			ft_error(4);
		i--;
	}
	if (close(f) < 0)
		ft_error(2);
}

void	ft_rd_stdin(int fd, int **map)
{
	char	buf;
	int		i;
	int		f;

	i = 1;
	f = open("1", O_TRUNC | O_RDWR);
	if (f == -1)
		ft_error(1);
	buf = '0';
	while (read(fd, &buf, 1))
		write(f, &buf, 1);
	if (close(f) < 0)
		ft_error(2);
	f = open("1", O_RDONLY);
	if (f == -1)
		ft_error(1);
	ft_map_std(&map, f);
	f = open("1", O_RDONLY);
	ft_rd(f, map);
	ft_alg(map);
	if (close(f) < 0)
		ft_error(2);
}
