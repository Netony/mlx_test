/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:05:35 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 17:25:04 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "dot.h"

double	degree_to_radian(double degree);

void	fdf_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	dot_mapdel(vars->map);
	dot_mapdel(vars->origin);
	exit(0);
}

void	fdf_put_translate(t_vars *vars, int x, int y)
{
	map_translate(vars->map, x, y, 0);
	fdf_putmap(vars, vars->map);
}

void	fdf_put_rotate(t_vars *vars, double a, double b, double c)
{
	map_rotate(vars->map, a, b, c);
	fdf_putmap(vars, vars->map);
}

void	fdf_put_zoom(t_vars *vars, int p)
{
	map_zoom(vars->map, p);
	fdf_putmap(vars, vars->map);
}

void	fdf_put_isometric(t_vars *vars)
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
