/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:02:28 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 12:03:35 by dajeon           ###   ########.fr       */
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
	image_set_tab(img, map);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	fdf_image_destroy(vars, img);
}

static void	image_set_dot(t_img *img, t_dot *dot)
{
	t_dot	*center;
	int		row;
	int		col;

	row = dot->y;
	col = dot->x;
	fdf_image_set(img, row, col, dot->color);
}

static void	image_set_row(t_img *img, t_dot **row)
{
	int	j;

	j = 0;
	while (row[j])
		image_set_dot(img, row[j++]);
}

static void	image_set_tab(t_img *img, t_dot ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		image_set_row(img, tab[i++]);
}
/*
void	fdf_set(void *mlx_ptr, void *win_ptr, t_cood *a, t_cood *b)
{
	int		i;
	int		n;
	t_cood	*cur;

	n = abs(larger(a->x - b->x, a->y - b->y));
	i = 0;
	while (i < n)
	{
		cur = cood_iofn(a, b, i, n);
		mlx_put_cood(mlx_ptr, win_ptr, cur);
		i++;
	}
}
*/
