/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:36:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	char	*path = "42.fdf";
	t_vars	vars;

	vars.map = fdf_map_parse(path);
	dup_zoom(vars.map, 200);
	dup_rotate(vars.map, 0, -0.785, 0.615);
	dup_translate(vars.map, 640, 360);
	vars.width = 1280;
	vars.height = 720;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Tutorial");
	fdf_putmap(&vars, vars.map);
	fdf_hook(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

/*
int	test(void)
{
	vars.x = 200;
	vars.y = 400;
	vars.a = 0.615;
	vars.b = 0.785;

}
*/
