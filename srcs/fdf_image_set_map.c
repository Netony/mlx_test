/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_set_dot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 14:52:52 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_utils.h"
#include "dot.h"

static void	fdf_image_set_col(t_vars *vars, t_img *img, t_dot ***dup);
static void	fdf_image_set_row(t_vars *vars, t_img *img, t_dot ***dup);
static int	dot_larger_size(t_dot *d1, t_dot *d2);
static void	fdf_image_set_line(t_vars *vars, t_img *img, t_dot *d1, t_dot *d2);

void	fdf_image_set_map(t_vars *vars, t_img *img, t_dot ***dup)
{
	fdf_image_set_col(vars, img, dup);
	fdf_image_set_row(vars, img, dup);
}

static void	fdf_image_set_col(t_vars *vars, t_img *img, t_dot ***dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i + 1])
	{
		j = 0;
		while (dup[i][j])
		{
			fdf_image_set_line(vars, img, dup[i][j], dup[i + 1][j]);
			j++;
		}
		i++;
	}
}

static void	fdf_image_set_row(t_vars *vars, t_img *img, t_dot ***dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j + 1])
		{
			fdf_image_set_line(vars, img, dup[i][j], dup[i][j + 1]);
			j++;
		}
		i++;
	}
}

static void	fdf_image_set_line(t_vars *vars, t_img *img, t_dot *d1, t_dot *d2)
{
	int				i;
	int				n;
	int				x;
	int				y;
	unsigned int	color;

	n = dot_larger_size(d1, d2);
	i = 0;
	while (i < n)
	{
		x = ft_iofn(d1->x, d2->x, i, n);
		y = ft_iofn(d1->y, d2->y, i, n);
		color = ft_color_iofn(d1->color, d2->color, i, n);
		if (fdf_image_set_check(vars, y, x))
			fdf_image_set(img, y, x, color);
		i++;
	}
}

static int	dot_larger_size(t_dot *d1, t_dot *d2)
{
	int	dx;
	int	dy;

	dx = d1->x - d2->x;
	dy = d1->y - d2->y;
	return (ft_larger(ft_abs(dx), ft_abs(dy)));
}
