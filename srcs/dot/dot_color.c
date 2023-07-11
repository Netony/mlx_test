/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:53 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 17:33:52 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"
#include "fdf_utils.h"

static int	map_get_z_max(t_dot ***map);
static int	map_get_z_min(t_dot ***map);
static int	map_check_no_color(t_dot ***map);

void	map_highlight(t_dot ***map, unsigned int color, int weight)
{
	int	max;
	int	min;
	int	i;
	int	j;

	max = map_get_z_max(map);
	min = map_get_z_min(map);
	if (map_check_no_color(map) == 0)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->color = ft_color_iofn(0x00FFFFFF, color, \
					map[i][j]->z - min, ft_larger(weight, max - min));
			j++;
		}
		i++;
	}
}

static int	map_check_no_color(t_dot ***map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j]->color != 0x00FFFFFF)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	map_get_z_max(t_dot ***map)
{
	int	i;
	int	j;
	int	max;

	max = map[0][0]->z;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			max = ft_larger(max, map[i][j]->z);
			j++;
		}
		i++;
	}
	return (max);
}

static int	map_get_z_min(t_dot ***map)
{
	int	i;
	int	j;
	int	min;

	min = map[0][0]->z;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			min = ft_smaller(min, map[i][j]->z);
			j++;
		}
		i++;
	}
	return (min);
}
