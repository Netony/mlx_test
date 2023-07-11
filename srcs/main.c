/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 18:58:11 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_set_window(t_vars *vars, int width, int height);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		set_error_argument();
		error_exit("fdf");
	}
	vars.origin = fdf_map_parse(argv[1], 5);
	if (vars.origin == NULL)
		error_exit("fdf");
	map_highlight(vars.origin, 0x009FC93C, 10);
	fdf_set_window(&vars, 1920, 1080);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FDF");
	if (fdf_put_start(&vars) < 0)
		error_exit("fdf");
	fdf_hook(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	fdf_set_window(t_vars *vars, int width, int height)
{
	vars->width = width;
	vars->height = height;
}
