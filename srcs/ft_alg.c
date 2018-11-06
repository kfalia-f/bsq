/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:18:24 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/06 12:16:36 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_map(char ***map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		i++;
	}
}

void	ft_alg(char ***map)
{
	int 	i;
	int 	j;
	int		maxi;
	int		maxj;
	int		max;
	int		**r;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == g_em)
				r[i][j] = 1;
			else
				r[i][j] = 0;
		j++;
		}
	i++;
	}
	i = 1;
	j = 1;
	while (r[i])
	{
		j = 0;
		while (r[i][j])
		{
			r[i][j] += ft_min(r[i - 1][j - 1], r[i - 1][j], r[i][j - 1]);
			if (r[i][j] > max)
			{
				max = r[i][j];
				maxi = i;
				maxj = j;
			}
			j++;
		}
		i++;
	}
	i = maxi;
	while (i != (maxi - max))
	{
		j = maxj;
		while (j != (maxj - max))
		{
			map[i][j] = g_fu;
			j--;
		}
		i--;
	}
	ft_print_map(&map);
}
