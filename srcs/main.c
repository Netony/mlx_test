/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 17:14:20 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	char	*path = "42.fdf";
	t_vars	vars;

	vars.map = fdf_parse(path);
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
}
*/
