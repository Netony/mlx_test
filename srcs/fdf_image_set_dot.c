/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_set_dot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:36:56 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_image_set_col(t_img *img, t_dot ***dup);
static void	fdf_image_set_row(t_img *img, t_dot ***dup);

void	fdf_image_set_dot(t_img *img, t_dot *dot)
{
	if (fdf_image_set_check(dot->x, dot->y))
		fdf_image_set(img, dot->x, dot->y, dot->color);
}

void	fdf_image_set_line(t_img *img, t_dot *d1, t_dot *d2)
{
	int		i;
	int		n;
	int		x;
	int		y;
	int		color;

	n = dot_larger_size(d1, d2);
	i = 0;
	while (i < n)
	{
		x = ft_iofn(d1->x, d2->x, i, n);
		y = ft_iofn(d1->y, d2->y, i, n);
		color = d1->color;
		if (fdf_image_set_check(y, x))
			fdf_image_set(img, y, x, color);
		i++;
	}
}

void	fdf_image_set_map(t_img *img, t_dot ***dup)
{
	fdf_image_set_col(img, dup);
	fdf_image_set_row(img, dup);
}

static void	fdf_image_set_col(t_img *img, t_dot ***dup)
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

static void	fdf_image_set_row(t_img *img, t_dot ***dup)
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
