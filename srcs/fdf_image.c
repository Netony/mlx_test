/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:43:39 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 13:44:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_image_init(t_vars *vars, t_img *img)
{
	img->img = mlx_new_image(vars->mlx, 640, 360);
	img->addr = \
		mlx_get_data_addr(img->img, &(img->bpp), &(img->row), &(img->endian));
	if (img->addr == 0)
		return (-1);
	return (0);
}

void	image_set_pixel(t_img *img, int x, int y, int color)
{
	char			*dst;

	dst = img->addr;
	dst += img->row * y;
	dst += (img->bpp / 8) * x;
	*(unsigned int *)dst = color;
}
