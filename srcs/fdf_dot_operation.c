/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:41:29 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 10:01:17 by dajeon           ###   ########.fr       */
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

void	dot_scalar_percent(t_dot *dot, int p)
{

	dot->x = dot->x * p / 100;
	dot->y = dot->y * p / 100;
	dot->z = dot->z * p / 100;
}
