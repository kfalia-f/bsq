/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:52:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/06 13:31:42 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_map(char ***map, char *argv)
{
	int		fd;
	int		len;
	char	sym;
	int		k;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	fd = ft_param(&len, fd);
	k = 0;
	while (sym != '\n')
	{
		read(fd, &sym, 1);
		k++;
	}
	*map = (char **)malloc(len * sizeof(char *));
	if (!map)
		ft_error(4);
	while (len - 1 > 0)
	{
		(*map)[len - 1] = (char *)malloc(k * sizeof(char));
		if (!(*map))
			ft_error(4);
		len--;
	}
	close(fd);
}

int		ft_param(int *len, int fd)
{
	int		i;
	int		fd;
	char	sym;
	char	*buff;

	i = 0;
	while (sym != '\n')
	{
		read(fd, &sym, 1);
		buff[i++] = sym;
	}
	buff[i] = '\0';
	(*len) = ft_atoi(buff);
	i = 0;
	while (*(buff + i) >= '0' && *(buff + i) <= '9')
		i++;
	g_em = buff[i++];
	g_ob = buff[i++];
	g_fu = buff[i++];
	if (g_em == g_ob || g_ob == g_fu || g_em == g_fu)
		ft_error(3);
	return (fd);
}
