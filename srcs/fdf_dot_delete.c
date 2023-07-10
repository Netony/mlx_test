/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:21:23 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 17:58:41 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_dot_arr_delete_n(t_dot **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

void	fdf_dot_map_delete_n(t_dot ***map, int n)
{
	int	i;

	i = 0;
	while (i < n)
		fdf_dot_arr_delete(map[i++]);
	free(map);
}

void	fdf_dot_arr_delete(t_dot **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	fdf_dot_map_delete(t_dot ***map)
{
	int	i;

	i = 0;
	while (map[i])
		fdf_dot_arr_delete(map[i++]);
	free(map);
}
