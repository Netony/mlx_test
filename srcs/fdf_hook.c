/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:01:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:53:02 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hook_key(int keycode, t_vars *vars);
void	hook_move(int keycode, t_vars *vars);
void	hook_close(int keycode, t_vars *vars);
void	move(t_vars *vars, int x, int y);

void	fdf_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 0, hook_key, vars);
}

static int	hook_key(int keycode, t_vars *vars)
{
	hook_close(keycode, vars);
	hook_move(keycode, vars);
	return (0);
}

void	move(t_vars *vars, int x, int y)
{
	map_action(vars->map, fdf_move, x, y);
	fdf_putmap(vars, vars->map);
}

void	hook_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		fdf_close(vars);
}

void	hook_move(int keycode, t_vars *vars)
{
	if (keycode == 40)
		move(vars, -10, 0);
	if (keycode == 38)
		move(vars, 10, 0);
	if (keycode == 4)
		move(vars, 0, -10);
	if (keycode == 37)
		move(vars, 0, 10);
}
