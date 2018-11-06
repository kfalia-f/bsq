/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:31:26 by rnarbo            #+#    #+#             */
/*   Updated: 2018/11/04 18:42:57 by rnarbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_diff.h"

int		count_line_w(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int		count_lines(char *str)
{
	int		lc;

	lc = 0;
	while (*str)
	{
		if (*str == '\n')
			lc++;
		str++;
	}
	return (lc);
}

void	print_rush(int r_num, int w, int h)
{
	char	tmp;

	tmp = r_num + '0';
	write(1, "[rush-0", 7);
	write(1, &tmp, 1);
	write(1, "] [", 3);
	while (w != 0)
	{
		tmp = w % 10 + '0';
		write(1, &tmp, 1);
		w /= 10;
	}
	write(1, "] [", 3);
	while (h != 0)
	{
		tmp = h % 10 + '0';
		write(1, &tmp, 1);
		h /= 10;
	}
	write(1, "]", 1);
}

void	ft_diff(char *str)
{
	int		w;
	int		h;
	int		r_num;
	int		flag;
	char	*rush;

	w = count_line_w(str);
	h = count_lines(str);
	flag = 0;
	r_num = 0;
	while (r_num < 5)
	{
		rush = do_rush(r_num, w, h);
		if (ft_strcmp(str, rush) == 0 && w != 0 && h != 0)
		{
			if (flag)
				write(1, " || ", 4);
			print_rush(r_num, w, h);
			flag = 1;
		}
		free(rush);
		r_num++;
	}
	if (!flag)
		write(1, "aucune", 6);
}

int		main(void)
{
	char	*rush;

	rush = read_task();
	ft_diff(rush);
	write(1, "\n", 1);
	free(rush);
	return (0);
}
