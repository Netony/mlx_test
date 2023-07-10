/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:51:24 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 18:06:19 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_dot_arr_size(t_dot **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	fdf_dot_map_size(t_dot ***map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	fdf_dot_map_row_size(t_dot ***map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

int	fdf_dot_map_col_size(t_dot ***map)
{
	int	col;

	col = 0;
	while (map[0][col])
		col++;
	return (col);
}
