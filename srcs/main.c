/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:31:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/05 19:13:44 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	test(t_img *img);

int	main(void)
{
	t_vars	vars;
	t_img	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 360, "Tutorial");
	fdf_image_init(&vars, &img);
	fdf_pixel_put(&img, 300, 300, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

int	fdf_image_init(t_vars *vars, t_img *img)
{
	img->img = mlx_new_image(vars->mlx, 640, 360);
	img->addr = \
		mlx_get_data_addr(img->img, &(img->bpp), &(img->row), &(img->endian));
	if (img->addr == 0)
		return (-1);
	return (0);
}

void	image_pixel_set(t_img *img, int x, int y, int color)
{
	char			*dst;

	dst = img->addr;
	dst += img->row * y;
	dst += (img->bpp / 8) * x;
	*(unsigned int *)dst = color;
}
