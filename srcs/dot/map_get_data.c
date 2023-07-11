/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:52:23 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 16:20:31 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"
#include "fdf_utils.h"

int	map_get_x_center(t_dot ***map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = map[0][0]->x;
	min = map[0][0]->x;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->x);
			max = ft_larger(max, map[i][j]->x);
			j++;
		}
		i++;
	}
	return ((max + min) / 2);
}

int	map_get_y_center(t_dot ***map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = map[0][0]->y;
	min = map[0][0]->y;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->y);
			max = ft_larger(max, map[i][j]->y);
			j++;
		}
		i++;
	}
	return ((max + min) / 2);
}

int	map_get_z_center(t_dot ***map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = map[0][0]->z;
	min = map[0][0]->z;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->z);
			max = ft_larger(max, map[i][j]->z);
			j++;
		}
		i++;
	}
	return ((max + min) / 2);
}

int	map_get_row_size(t_dot ***map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

int	map_get_col_size(t_dot ***map)
{
	int	col;

	col = 0;
	while (map[0][col])
		col++;
	return (col);
}
