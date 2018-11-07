/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:20:31 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/07 16:34:35 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readtask.h"

int		ft_realloc(char **buff, int size)
{
	char	*nbuff;
	int		i;
	int		nsize;

	if (!buff)
		return (0);
	if ((nbuff = (char *)malloc(size * 2)) == 0)
	{
		free(*buff);
		return (0);
	}
	else
		nsize = size * 2;
	i = 0;
	while (i < size)
	{
		nbuff[i] = (*buff)[i];
		i++;
	}
	free(*buff);
	*buff = nbuff;
	return (nsize);
}

char	*read_task(void)
{
	int		i;
	char	buff;
	char	*string;
	int		size;

	size = 4;
	string = (char *)malloc(size);
	i = 0;
	while (read(0, &buff, 1) > 0)
	{
		if (i == size)
			if ((size = ft_realloc(&string, size)) == 0)
				return (0);
		string[i++] = buff;
	}
	if (i == size)
		if ((size = ft_realloc(&string, size)) == 0)
			return (0);
	string[i] = 0;
	return (string);
}
