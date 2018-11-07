/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdfl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:54:56 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 20:02:58 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_rdfl(int argc, char **argv, int ***map)
{
	int		i;
	int		fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_error(1);
		ft_map(map, argv[i]);
		ft_rd(fd, *map);
		ft_alg(*map);
		if (close(fd) < 0)
			ft_error(2);
		i++;
		if (i + 1 <= argc)
			ft_putchar('\n');
	}
	return (1);
}
