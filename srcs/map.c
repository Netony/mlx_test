/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:28:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 21:47:52 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_map	*ft_mapnew(t_dot ***dots, int row, int col)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->dots = dots;
	map->row = row;
	map->col = col;
	return (map);
}
*/

/*
void	ft_mapdel(t_map *map)
{
	ft_map
}
*/

t_map	*ft_mapnew(t_dot ***dots, int row, int col)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	(void)dots;
	map->row = row;
	map->col = col;
	return (map);
}
