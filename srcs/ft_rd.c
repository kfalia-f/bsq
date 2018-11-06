/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:54:09 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/06 12:12:30 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rd(int fd, char **map)
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
		{
			if (buf != '\n')
			{
				map[i][j] = buf;
				j++;
			}
			else
			{
				map[i][j] = '\0';
				i++;
				j = 0;
			}
		}
	}
}
