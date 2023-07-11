/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:28:20 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 10:04:24 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dup_translate(t_dot ***dup, int x, int y, int z)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_add(dup[i][j], x, y, z);
			j++;
		}
		i++;
	}
}

void	dup_rotate(t_dot ***dup, double a, double b, double c)
{
	int	i;
	int	j;
	int	x_center;
	int	y_center;
	int	z_center;

	x_center = get_center_x(dup);
	y_center = get_center_y(dup);
	z_center = get_center_z(dup);
	dup_translate(dup, -x_center, -y_center, -z_center);
	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_rotate(dup[i][j], a, b, c);
			j++;
		}
		i++;
	}
	dup_translate(dup, x_center, y_center, z_center);
}

void	dup_zoom(t_dot ***dup, int p)
{
	int	i;
	int	j;
	int	x_center;
	int	y_center;
	int	z_center;

	x_center = get_center_x(dup);
	y_center = get_center_y(dup);
	z_center = get_center_z(dup);
	dup_translate(dup, -x_center, -y_center, -z_center);
	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_scalar_percent(dup[i][j], p);
			j++;
		}
		i++;
	}
	dup_translate(dup, x_center, y_center, z_center);
}	
