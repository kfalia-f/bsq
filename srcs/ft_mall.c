/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:52:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/05 18:05:46 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_mall(char ***map, char *argv)
{
	int		fd;
	int		a;
	char	i;
	char	buf[4];
	int		k;
	int		d;

	fd = open(argv, O_RDONLY);
	read(fd, &i, 1);
	a = i - '0';
	read(fd, buf, 4);
	k = 0;
	while (i != '\n')
	{
		read(fd, &i, 1);
		k++;
	}
	d = 0;
	*map = (char **)malloc(a * sizeof(char *));
	while (d < a)
	{
		(*map)[d] = (char *)malloc(k * sizeof(char));
		d++;
	}
	close(fd);
}
