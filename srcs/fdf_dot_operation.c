/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:41:29 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:22:32 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_add(t_dot *dot, int x, int y, int z)
{
	dot->x += x;
	dot->y += y;
	dot->z += z;
}

void	dot_transform(t_dot *dot, double **matrix)
{
	double	x;
	double	y;
	double	z;

	x = dot->x;
	y = dot->y;
	z = dot->z;
	dot->x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
	dot->y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
	dot->z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
}

void	dot_iofn(t_dot *center, t_dot *dot, int i, int n)
{
	dot->x = ft_iofn(center->x, dot->x, i, n);
	dot->y = ft_iofn(center->y, dot->y, i, n);
	dot->z = ft_iofn(center->z, dot->z, i, n);
}

void	dot_sum(t_dot *a, t_dot *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void	dot_sub(t_dot *a, t_dot *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}
