/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:39:10 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/07 20:01:56 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_param(int fd)
{
	int		i;
	char	sym;
	char	buff[10];

	i = 0;
	sym = '0';
	while (sym != '\n')
	{
		read(fd, &sym, 1);
		buff[i++] = sym;
	}
	buff[i] = '\0';
	g_len = ft_atoi(buff);
	i = 0;
	while (*(buff + i) >= '0' && *(buff + i) <= '9')
		i++;
	g_em = buff[i++];
	g_ob = buff[i++];
	g_fu = buff[i++];
	if (buff[++i] != '\0' || g_em == g_ob || g_ob == g_fu || g_em == g_fu)
		ft_error(3);
	return (fd);
}
