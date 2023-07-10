/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:25:59 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 19:17:36 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	**fdf_dot_parse_array(char **s, int i, int weight);

t_dot	*ft_dotnew(int x, int y, int z, int color)
{
	t_dot	*new;

	new = (t_dot *)malloc(sizeof(t_dot));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	if (color == 0)
		new->color = 0x00FFFFFF;
	else
		new->color = color;
	return (new);
}

t_dot	*fdf_dot_parse(char *s, int i, int j, int weight)
{
	int		z;
	int		c;

	z = ft_atoi(s);
	c = ft_atoi_new(s + ft_nextptr(s, ", "));
	return (ft_dotnew(i * weight, j * weight, z, c));
}

static t_dot	**fdf_dot_parse_array(char **s, int i, int weight)
{
	t_dot	**array;
	int		j;

	array = (t_dot **)malloc(sizeof(t_dot *) * (ft_sptsize(s) + 1));
	j = 0;
	while (s[j])
	{
		array[j] = fdf_dot_parse(s[j], i, j, weight);
		if (array[j] == NULL)
		{
			fdf_dot_arr_delete_n(array, j);
			return (NULL);
		}
		j++;
	}
	array[j] = NULL;
	return (array);
}

t_dot	***fdf_dot_parse_map(char ***s, int weight)
{
	t_dot	***map;
	int		i;

	map = (t_dot ***)malloc(sizeof(t_dot **) * (ft_tabsize(s) + 1));
	i = 0;
	while (s[i])
	{
		map[i] = fdf_dot_parse_array(s[i], i, weight);
		if (map[i] == NULL)
		{
			fdf_dot_map_delete_n(map, i);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}
