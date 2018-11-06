/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:58:01 by jmaynard          #+#    #+#             */
/*   Updated: 2018/11/06 18:24:44 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add(int ***map, int *size)
{
	int i;

	i = 0;
	while (i < g_len)
	{
		(*map)[i] = (int *)malloc((*size) * sizeof(int));
		i++;
	}
	*size = -1;
}

void	ft_map_in(int **map, int fd)
{
	char	sym;
	int		i;
	int		j;

	i = 1;
	while (i < g_len)
	{
		j = 0;
		while (sym != '\n')
		{
			read(fd, &sym, 1);
			if (sym == g_ob)
				map[i][j] = 0;
			else if (sym == g_em)
				map[i][j] = 1;
			else
				map[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	ft_stdin(int **map)
{
	char	sym;
	int		fd;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	sym = '\0';
	fd = ft_param(0);
	map = (int **)malloc(g_len * sizeof(int *));
	while (sym != '\n')
	{
		read(fd, &sym, 1);
		str[i++] = sym;
	}
	ft_add(&map, &i);
	while (str[++i] != '\n')
	{
		if (str[i] == g_ob)
			map[0][i] = 0;
		else if (str[i] == g_em)
			map[0][i] = 1;
	}
	map[0][i] = -1;
	ft_map_in(map, fd);
}
