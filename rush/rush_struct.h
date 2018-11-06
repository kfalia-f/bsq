/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:25:46 by rnarbo            #+#    #+#             */
/*   Updated: 2018/11/03 20:31:45 by rnarbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RUSH_STRUCT_H
#	define RUSH_STRUCT_H

typedef struct	s_rstruct
{
	char left_top;
	char right_top;
	char left_bot;
	char right_bot;
	char vert_b;
	char horiz_b;
}				t_rstruct;

t_rstruct		g_rush[] =
{
	{'o', 'o', 'o', 'o', '|', '-'},
	{'/', '\\', '\\', '/', '*', '*'},
	{'A', 'A', 'C', 'C', 'B', 'B'},
	{'A', 'C', 'A', 'C', 'B', 'B'},
	{'A', 'C', 'C', 'A', 'B', 'B'}
};

#	endif
