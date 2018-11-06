/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:52:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/06 17:49:38 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_map(int ***map, char *argv)
{
	int		fd;
	char	sym;
	int		k;
	int		i;

	sym = '0';
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	fd = ft_param(fd);
	k = 0;
	while (sym != '\n')
	{
		read(fd, &sym, 1);
		k++;
	}
	*map = (int **)malloc(g_len * sizeof(int *));
	if (!map)
		ft_error(4);
	i = g_len - 1;
	while (i >= 0)
	{
		(*map)[i] = (int *)malloc(k * sizeof(int));
		if (!(*map))
			ft_error(4);
		i--;
	}
	if (close(fd) < 0)
		ft_error(2);
}
