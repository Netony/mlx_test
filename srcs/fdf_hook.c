/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:01:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 10:39:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hook_key(int keycode, t_vars *vars);
void		hook_close(int keycode, t_vars *vars);
void		hook_translate(int keycode, t_vars *vars);
void		translate_put(t_vars *vars, int x, int y);
void		hook_rotate(int keycode, t_vars *vars);
void		rotate_put(t_vars *vars, double a, double b);
void		hook_zoom(int keycode, t_vars *vars);
void		zoom_put(t_vars *vars, int p);

void	fdf_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 0, hook_key, vars);
}

static int	hook_key(int keycode, t_vars *vars)
{
	hook_close(keycode, vars);
	hook_translate(keycode, vars);
	hook_rotate(keycode, vars);
	hook_zoom(keycode, vars);
	return (0);
}

void	hook_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		fdf_close(vars);
}

void	translate_put(t_vars *vars, int x, int y)
{
	dup_translate(vars->map, x, y, 0);
	fdf_putmap(vars, vars->map);
}

void	rotate_put(t_vars *vars, double a, double b)
{
	dup_rotate(vars->map, a, b, 0);
	fdf_putmap(vars, vars->map);
}

void	zoom_put(t_vars *vars, int p)
{
	dup_zoom(vars->map, p);
	fdf_putmap(vars, vars->map);
}

void	hook_zoom(int keycode, t_vars *vars)
{
	if (keycode == 24)
		zoom_put(vars, 110);
	else if (keycode == 27)
		zoom_put(vars, 90);
	
}

void	hook_translate(int keycode, t_vars *vars)
{
	if (keycode == 40)
		translate_put(vars, 0, -10);
	if (keycode == 38)
		translate_put(vars, 0, 10);
	if (keycode == 4)
		translate_put(vars, -10, 0);
	if (keycode == 37)
		translate_put(vars, 10, 0);
}

void	hook_rotate(int keycode, t_vars *vars)
{
	if (keycode == 123)
		rotate_put(vars, -0.1, 0);
	if (keycode == 124)
		rotate_put(vars, 0.1, 0);
	if (keycode == 125)
		rotate_put(vars, 0, 0.1);
	if (keycode == 126)
		rotate_put(vars, 0, -0.1);
}
