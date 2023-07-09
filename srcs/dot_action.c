/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:56:15 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 08:49:12 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_oper(t_dot ***map, void (*f)(t_dot *, int, int, int))
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			f(map[i][j]);
			j++;
		}
		i++;
	}
}

void	fdf_move(t_dot *dot, int x, int y, int z)
{
	dot->x += x;
	dot->y += y;
}

void	fdf_rotate(t_dot ***map, int x, int y, int z)
{
	
}

t_dot	*map_center(t_dot ***map)
{
	int	i;
	int	j;

	i = ft_maprow(map);
	j = ft_mapcol(map);
	return (map[i][j]);
}
