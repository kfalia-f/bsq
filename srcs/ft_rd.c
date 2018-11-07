/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:54:09 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 14:20:35 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill(int **map, int *i, int *j, char buf)
{
	if (buf == g_em)
		map[*i][(*j)++] = 1;
	else if (buf == g_ob)
		map[*i][(*j)++] = 0;
	else if (buf == '\n')
	{
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
	int		ret;
	int		flag;
	char	buf;

	i = 0;
	j = 0;
	flag = 0;
	while ((ret = read(fd, &buf, BUF_SIZE)))
	{
		if (flag != 5)
			flag++;
		else
			ft_fill(map, &i, &j, buf);
	}
}
