/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 17:40:50 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error_argument();
	vars.origin = fdf_map_parse(argv[1], 5);
	if (vars.origin == NULL)
		error_errno();
	vars.width = 1920;
	vars.height = 1080;
	map_highlight(vars.origin, 0x009FC93C, 10);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FDF");
	if (fdf_put_start(&vars) < 0)
		error_errno();
	fdf_hook(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
