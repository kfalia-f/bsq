/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:28:21 by jmaynard          #+#    #+#             */
/*   Updated: 2018/11/07 14:14:14 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_number(int *num, char *str, int *flaq)
{
	if (((int)*str >= 48) && ((int)*str <= 57))
		*num += *str - 48;
	if (((int)*(str + 1) >= 48) && ((int)*(str + 1) <= 57))
		*num *= 10;
	else
		*flaq = 0;
}

int		ft_atoi(char *str)
{
	int i;
	int num;
	int flaq;
	int sign;

	i = 0;
	num = 0;
	flaq = 1;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && flaq > 0)
	{
		(((int)str[i] >= 48) && ((int)str[i] <= 57)) ?
			(ft_number(&num, &str[i], &flaq)) : (flaq = 0);
		i++;
	}
	if (num > 0)
		return (num * sign);
	ft_error(3);
}
