/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:16:56 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 18:19:02 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_map_parse_two(char ***tab)
{
	//t_dot	***dots;
	t_map	*map;

	map = ft_mapnew(NULL, ft_tab_rowsize(tab),
			ft_tab_colsize(tab));
	/*
	if (map == NULL)
		return (NULL);
	dots = tab_to_map(map, tab); 
	ft_tabdel(tab);
	if (map->dots == NULL)
		return (NULL);
	map->dots = dots;
	*/
	return (map);
}

t_map	*ft_map_parse(int fd)
{
	char	***tab;
	t_map	*map;
	
	tab = ft_map_parse_one(fd);
	if (tab == NULL)
		return (NULL);
	map = ft_map_parse_two(tab);
	if (map == NULL)
		return (NULL);
	return (map);
}

