/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:58:01 by jmaynard          #+#    #+#             */
/*   Updated: 2018/11/06 13:31:29 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add(char ***map, int size)
{
	char	**nmap;
	

void	ft_stdin(char **map)
{
	char	sym;
	int		len;
	int		fd;

	fd = ft_param(&len, 0);
	map = (char *)malloc(len * sizeof(char *));
	while(sym != '\n')
	{
		read(fd, &sym, 1);
		map
	ft_add(&map, wid);
