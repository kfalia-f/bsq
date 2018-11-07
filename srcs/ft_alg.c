/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:18:24 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 21:32:06 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_map(int **map)
{
	int		i;
	int		j;

	i = 0;
	while (i != g_len)
	{
		j = 0;
		while (map[i][j] != -1)
		{
			if (map[i][j] == 0)
				ft_putchar(g_ob);
			else if (map[i][j] == (int)g_fu)
				ft_putchar(g_fu);
			else if (map[i][j] > 0)
				ft_putchar(g_em);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_max(int **map, int max, int maxi, int maxj)
{
	int i;
	int j;

	i = maxi;
	while (i != (maxi - max))
	{
		j = maxj;
		while (j != (maxj - max))
		{
			map[i][j] = (int)g_fu;
			j--;
		}
		i--;
	}
	ft_print_map(map);
}

int		ft_min(int a, int b, int c)
{
	int min;

	min = a;
	if (b < min)
		min = b;
	else if (c < min)
		min = c;
	return (min);
}

int		ft_find(int **map, int i, int j)
{
	map[i][j] += ft_min(map[i - 1][j - 1],
			map[i - 1][j], map[i][j - 1]);
	return (map[i][j]);
}

void	ft_alg(int **map)
{
	int		i;
	int		j;
	int		max;
	int		maxi;
	int		maxj;

	max = 0;
	i = 1;
	while (i != g_len)
	{
		j = 1;
		while (map[i][j] != -1)
		{
			if (map[i][j] != 0)
				if (ft_find(map, i, j) > max)
				{
					max = map[i][j];
					maxi = i;
					maxj = j;
				}
			j++;
		}
		i++;
	}
	ft_max(map, max, maxi, maxj);
}
