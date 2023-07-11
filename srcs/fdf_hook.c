/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:01:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 16:02:13 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_close(t_vars *vars);

void		hook_key_close(int keycode, t_vars *vars);
void		hook_key_translate(int keycode, t_vars *vars);
void		hook_key_rotate(int keycode, t_vars *vars);
void		hook_key_zoom(int keycode, t_vars *vars);
void		hook_key_reset(int keycode, t_vars *vars);

static int	hook_key(int keycode, t_vars *vars);
static int	hook_button(t_vars *vars);

void	fdf_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 0, hook_key, vars);
	mlx_hook(vars->win, 17, 0, hook_button, vars);
}

static int	hook_key(int keycode, t_vars *vars)
{
	hook_key_close(keycode, vars);
	hook_key_translate(keycode, vars);
	hook_key_rotate(keycode, vars);
	hook_key_zoom(keycode, vars);
	hook_key_reset(keycode, vars);
	return (0);
}

static int	hook_button(t_vars *vars)
{
	fdf_close(vars);
	return (0);
}
