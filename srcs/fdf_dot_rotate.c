/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:49:33 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:36:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static double	**row_to_matrix(double *(*get)(double), double r);
static double	*get_roll_row(double c);
static double	*get_pitch_row(double c);
static double	*get_yaw_row(double c);

void	dot_rotate(t_dot *dot, double a, double b, double c)
{
	double	**yaw;
	double	**pitch;
	double	**roll;

	yaw = row_to_matrix(get_yaw_row, c);
	pitch = row_to_matrix(get_pitch_row, b);
	roll = row_to_matrix(get_roll_row, a);
	dot_transform(dot, yaw);
	dot_transform(dot, pitch);
	dot_transform(dot, roll);
	ft_matrix_del(yaw, 3, 3);
	ft_matrix_del(pitch, 3, 3);
	ft_matrix_del(roll, 3, 3);
}

static double	**row_to_matrix(double *(*get_row)(double), double r)
{
	double	*row;
	double	**matrix;

	row = get_row(r);
	matrix = ft_matrix_new(row, 3, 3);
	free(row);
	if (matrix == NULL)
		return (NULL);
	return (matrix);
}

static double	*get_roll_row(double c)
{
	double	*row;

	row = malloc(sizeof(double) * 9);
	if (row == NULL)
		return (NULL);
	row[0] = 1;
	row[1] = 0;
	row[2] = 0;
	row[3] = 0;
	row[4] = cos(c);
	row[5] = -sin(c);
	row[6] = 0;
	row[7] = sin(c);
	row[8] = cos(c);
	return (row);
}

static double	*get_pitch_row(double c)
{
	double	*row;

	row = malloc(sizeof(double) * 9);
	if (row == NULL)
		return (NULL);
	row[0] = cos(c);
	row[1] = 0;
	row[2] = sin(c);
	row[3] = 0;
	row[4] = 1;
	row[5] = 0;
	row[6] = -sin(c);
	row[7] = 0;
	row[8] = cos(c);
	return (row);
}

static double	*get_yaw_row(double c)
{
	double	*row;

	row = malloc(sizeof(double) * 9);
	if (row == NULL)
		return (NULL);
	row[0] = cos(c);
	row[1] = -sin(c);
	row[2] = 0;
	row[3] = sin(c);
	row[4] = cos(c);
	row[5] = 0;
	row[6] = 0;
	row[7] = 0;
	row[8] = 1;
	return (row);
}
