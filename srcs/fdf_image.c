/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:43:39 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:10:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*fdf_image_init(t_vars *vars)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	img->addr = \
		mlx_get_data_addr(img->img, &(img->bpp), &(img->row), &(img->endian));
	if (img->addr == 0)
	{
		free(img);
		return (NULL);
	}
	return (img);
}

void	fdf_image_destroy(t_vars *vars, t_img *img)
{
	mlx_destroy_image(vars->mlx, img->img);
	free(img);
}

void	fdf_image_set(t_img *img, int x, int y, int color)
{
	char			*dst;

	dst = img->addr;
	dst += img->row * y;
	dst += (img->bpp / 8) * x;
	*(unsigned int *)dst = color;
}
