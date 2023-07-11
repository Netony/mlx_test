/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:52:18 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 13:47:21 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"

void	map_translate(t_dot ***map, int x, int y, int z)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			dot_add(map[i][j], x, y, z);
			j++;
		}
		i++;
	}
}

void	map_rotate(t_dot ***map, double a, double b, double c)
{
	int	i;
	int	j;
	int	x_center;
	int	y_center;
	int	z_center;

	x_center = map_get_x_center(map);
	y_center = map_get_y_center(map);
	z_center = map_get_z_center(map);
	map_translate(map, -x_center, -y_center, -z_center);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			dot_rotate(map[i][j], a, b, c);
			j++;
		}
		i++;
	}
	map_translate(map, x_center, y_center, z_center);
}

void	map_zoom(t_dot ***map, int p)
{
	int	i;
	int	j;
	int	x_center;
	int	y_center;
	int	z_center;

	x_center = map_get_x_center(map);
	y_center = map_get_y_center(map);
	z_center = map_get_z_center(map);
	map_translate(map, -x_center, -y_center, -z_center);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			dot_scalar_p(map[i][j], p);
			j++;
		}
		i++;
	}
	map_translate(map, x_center, y_center, z_center);
}	
