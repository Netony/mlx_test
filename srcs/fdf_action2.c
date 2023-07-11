/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_action2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:29:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 17:25:04 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dot.h"

double	degree_to_radian(double degree);

int	fdf_put_start(t_vars *vars)
{
	vars->map = ft_mapdup(vars->origin);
	if (vars->map == NULL)
		return (-1);
	fdf_put_isometric(vars);
	return (0);
}

void	fdf_put_reset(t_vars *vars)
{
	int	ret;

	dot_mapdel(vars->map);
	ret = fdf_put_start(vars);
	if (ret < 0)
		error_errno();
}

void	fdf_put_oblique(t_vars *vars)
{
	int		x;
	int		y;
	int		z;
	double	pitch;
	double	yaw;

	pitch = degree_to_radian(-35.264);
	yaw = degree_to_radian(-45.0);
	x = map_get_x_center(vars->map);
	y = map_get_y_center(vars->map);
	z = map_get_z_center(vars->map);
	map_rotate(vars->map, 0, pitch, yaw);
	map_zoom(vars->map, 400);
	map_translate(vars->map, -x + vars->height / 2, -y + vars->width / 2, 0);
	fdf_putmap(vars, vars->map);
}
