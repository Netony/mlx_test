/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:49:39 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 07:52:31 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_maprow(t_dot ***map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

int	ft_mapcol(t_dot	***map)
{
	int	col;

	col = 0;
	while (map[0][col])
		col++;
	return (col);
}
