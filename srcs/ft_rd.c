/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:54:09 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 20:43:49 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check(int **map, int flag, int i, int j)
{
	i = 0;
	if (g_len < 2 || g_wid < 3)
	{
		while (i < g_len)
		{
			j = 0;
			while (j < g_wid)
			{
				if (map[i][j] == 1 && flag == 1)
				{
					ft_putchar(g_fu);
					flag = 2;
				}
				else if (map[i][j] == 0)
					ft_putchar(g_ob);
				else if (map[i][j] == 1)
					ft_putchar(g_em);
				else
					ft_putchar('\n');
				j++;
			}
			i++;
		}
		exit(EXIT_SUCCESS);
	}
}

void	ft_fill(int **map, int *i, int *j, char buf)
{
	if (buf == g_em)
		map[*i][(*j)++] = 1;
	else if (buf == g_ob)
		map[*i][(*j)++] = 0;
	else if (buf == '\n')
	{
		if ((*j) != g_wid - 1)
			ft_error(3);
		map[(*i)++][*j] = -1;
		(*j) = 0;
	}
	else
		ft_error(3);
}

void	ft_rd(int fd, int **map)
{
	int		i;
	int		j;
	int		flag;
	char	buf;

	i = 0;
	j = 0;
	flag = 0;
	while (read(fd, &buf, BUF_SIZE))
	{
		if (flag == 0 && buf != '\n')
			continue ;
		else if (flag == 0 && buf == '\n')
		{
			flag = 1;
			continue ;
		}
		else if (i < g_len)
			ft_fill(map, &i, &j, buf);
		else
			ft_error(3);
	}
	if (i != g_len)
		ft_error(3);
	ft_check(map, flag, i, j);
}
