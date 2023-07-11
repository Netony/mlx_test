/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:12:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 16:57:32 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_close(t_vars *vars);
void	fdf_put_translate(t_vars *vars, int x, int y);
void	fdf_put_rotate(t_vars *vars, double a, double b, double c);
void	fdf_put_zoom(t_vars *vars, int p);
void	fdf_put_reset(t_vars *vars);

void	hook_key_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		fdf_close(vars);
}

void	hook_key_zoom(int keycode, t_vars *vars)
{
	if (keycode == 24)
		fdf_put_zoom(vars, 110);
	else if (keycode == 27)
		fdf_put_zoom(vars, 90);
}

void	hook_key_translate(int keycode, t_vars *vars)
{
	if (keycode == 40)
		fdf_put_translate(vars, 10, 0);
	else if (keycode == 38)
		fdf_put_translate(vars, -10, 0);
	else if (keycode == 4)
		fdf_put_translate(vars, 0, 10);
	else if (keycode == 37)
		fdf_put_translate(vars, 0, -10);
}

void	hook_key_rotate(int keycode, t_vars *vars)
{
	if (keycode == 123)
		fdf_put_rotate(vars, -0.1, 0, 0);
	else if (keycode == 124)
		fdf_put_rotate(vars, 0.1, 0, 0);
	else if (keycode == 125)
		fdf_put_rotate(vars, 0, 0.1, 0);
	else if (keycode == 126)
		fdf_put_rotate(vars, 0, -0.1, 0);
	else if (keycode == 15)
		fdf_put_rotate(vars, 0, 0, -0.1);
	else if (keycode == 45)
		fdf_put_rotate(vars, 0, 0, 0.1);
}

void	hook_key_reset(int keycode, t_vars *vars)
{
	if (keycode == 29)
		fdf_put_reset(vars);
}
