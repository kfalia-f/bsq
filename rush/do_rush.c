/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:21:26 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/04 22:20:02 by rnarbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_rush.h"
#include "rush_struct.h"

char	*alloc_rush(int w, int h)
{
	char	*res;
	int		i;

	if ((res = (char *)malloc((w + 1) * h + 1)) == 0)
		return (0);
	res[0] = 0;
	if (w == 0 || h == 0)
		return (res);
	res[(w + 1) * h] = 0;
	i = 0;
	while (i < h)
		res[i++ * (w + 1) + w] = '\n';
	return (res);
}

char	*do_rush(int r_num, int w, int h)
{
	int		wi;
	int		hi;
	char	*res;

	hi = -1;
	if ((res = alloc_rush(w, h)) == 0)
		return (0);
	while ((wi = 0) == 0 && ++hi < h && w > 0)
		while (wi < w)
			if (hi == 0 && wi == 0)
				res[hi * (w + 1) + wi++] = g_rush[r_num].left_top;
			else if (hi == h - 1 && wi == 0)
				res[hi * (w + 1) + wi++] = g_rush[r_num].left_bot;
			else if (hi == 0 && wi == w - 1)
				res[hi * (w + 1) + wi++] = g_rush[r_num].right_top;
			else if (hi == h - 1 && wi == w - 1)
				res[hi * (w + 1) + wi++] = g_rush[r_num].right_bot;
			else if (hi == 0 || hi == h - 1)
				res[hi * (w + 1) + wi++] = g_rush[r_num].horiz_b;
			else if (wi == 0 || wi == w - 1)
				res[hi * (w + 1) + wi++] = g_rush[r_num].vert_b;
			else
				res[hi * (w + 1) + wi++] = ' ';
	return (res);
}
