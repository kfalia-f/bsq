/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdfl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:54:56 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/05 18:06:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_rdfl(int argc, char **argv, char ***map)
{
	int		i;
	int		fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(2, "open() error\n", 13);
			return (0);
		}
		ft_mall(map, argv[i]);
		ft_rd(fd, *map);
		i++;
	}
	if (close(fd) == -1)
	{
		write(2, "close() error\n", 14);
		return (0);
	}
	return (1);
}
