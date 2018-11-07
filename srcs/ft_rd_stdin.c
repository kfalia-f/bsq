/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:43:53 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 17:29:48 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rd_stdin(int fd, int **map)
{
	int		ret;
	char	buf;
	char	s[5];
	int		i;
	int		flag;

	i = 1;
	buf = '0';
	while ((ret = read(fd, &buf, 1)) && flag == 0)
	{
		s[0] = buf;
		if (buf != '\n')
		{
			read(fd, &buf, 1);
			s[i] = buf;
			i++;
			continue ;
		}
		flag = 1;
		ft_putnbr(g_len);
		s[i] = '\0';
		g_wid = i;
		i = 0;
		map = (int **)malloc(g_len * sizeof(int *));
		while (s[i] != '\0')
		{
			if (s[i] == g_em)
				*map[i] = 1;
			else
				*map[i] = 0;
		}
		*map[i] = -1;
	}
}
