/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:33:19 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 17:03:14 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		**map;

	map = NULL;
	if (argc == 1)
	{
		ft_param(0);
		ft_rd_stdin(0, map);
	}
	else if (ft_rdfl(argc, argv, &map) == 0)
		return (0);
	
	return (0);
}
