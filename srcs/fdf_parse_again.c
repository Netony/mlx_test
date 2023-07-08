/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_again.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:26:51 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 21:52:21 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

t_dot	*str_to_dot(int i, int j, char *s);
char	***ft_map_parse_one(int fd);
t_map	*ft_map_parse(int fd);

int	main(void)
{
	int	fd;

	fd = open("42.fdf", O_RDONLY);
	ft_map_parse_one(fd);
	close(fd);
	return (0);
}

char	***ft_map_parse_one(int fd)
{
	t_list	*line;
	char	**arr;
	char	***tab;

	line = get_line_list(fd);
	if (line == NULL)
		return (NULL);
	arr = list_to_chrp(line);
	ft_lstdclear(&line);
	if (arr == NULL)
		return (NULL);
	tab = arr_split(arr);
	ft_sptdel(arr);
	if (tab == NULL)
		return (NULL);
	return (tab);
}

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

