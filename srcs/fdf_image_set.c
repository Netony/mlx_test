/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:02:28 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 16:48:10 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	image_set_dot(t_img *img, t_dot *dot);
static void	image_set_row(t_img *img, t_dot **row);
static void	image_set_tab(t_img *img, t_dot ***tab);

void	fdf_putmap(t_vars *vars, t_dot ***map)
{
	t_img	*img;

	img = fdf_image_init(vars);
	fdf_image_set_map(img, map);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	fdf_image_destroy(vars, img);
}

static void	fdf_image_set_dot(t_img *img, t_dot *dot)
{
	fdf_image_set(img, row, col, dot->color);
}

void	fdf_image_set_map(t_img *img, t_dot ***dup)
{
	fdf_image_set_col(img, dup);
	fdf_image_set_row(img, dup);
}

void	fdf_image_set_col(t_img *img, t_dot ***dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i + 1])
	{
		j = 0;
		while (dup[i][j])
		{
			fdf_image_set_line(img, dup[i][j], dup[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	fdf_image_set_row(t_img *img, t_dot ***dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j + 1])
		{
			fdf_image_set_line(img, dup[i][j], dup[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	fdf_image_set_line(t_img *img, t_dot *d1, t_dot *d2)
{
	int		x;
	int		y;
	int		color;

	n = larger_size(d1, d2);
	i = 0;
	while (i < n)
	{
		x = ft_iofn(d1->x, d2->x, i, n);
		y = ft_iofn(d1->y, d2->y, i, n);
		color = d1->color;
		fdf_image_set(img, x, y, color);
		i++;
	}
}

int	larger_size(t_dot *d1, t_dot *d2)
{
	int	dx;
	int	dy;

	dx = d1->x - d2->x;
	dy = d1->y - d2->y;
	return (ft_larger(ft_abs(dx), ft_abs(dy)));
}
