/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:33:15 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 09:59:23 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_center_x(t_dot ***map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = map[0][0]->x;
	min = map[0][0]->x;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->x);
			max = ft_larger(max, map[i][j]->x);
			j++;
		}
		i++;
	}
	return ((max + min) / 2);
}

int	get_center_y(t_dot ***map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = map[0][0]->y;
	min = map[0][0]->y;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->y);
			max = ft_larger(max, map[i][j]->y);
			j++;
		}
		i++;
	}
	return ((max + min) / 2);
}

int	get_center_z(t_dot ***map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	max = map[0][0]->z;
	min = map[0][0]->z;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->z);
			max = ft_larger(max, map[i][j]->z);
			j++;
		}
		i++;
	}
	return ((max + min) / 2);
}
