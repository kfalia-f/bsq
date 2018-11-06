/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:19:51 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/04 20:19:54 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef DO_RUSH_H
#	define DO_RUSH_H

#include <stdlib.h>

void	free_rush(char **arr, int h);
char	*do_rush(int r_num, int w, int h);

#	endif
