/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 11:12:41 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		perror("fdf");
		return (1);
	}
	vars.map = fdf_map_parse(argv[1]);
	dup_zoom(vars.map, 200);
	dup_rotate(vars.map, 0, -0.785, 0.615);
	dup_translate(vars.map, get_center_640, 360, 0);
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
