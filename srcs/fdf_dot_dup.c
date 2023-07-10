/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:15:11 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 19:20:16 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dot	**ft_arrdup(t_dot **arr);

t_dot	*ft_dotdup(t_dot *dot)
{
	t_dot	*dup;

	dup = ft_dotnew(dot->x, dot->y, dot->z, dot->color);
	return (dup);
}

t_dot	***ft_mapdup(t_dot ***map)
{
	t_dot	***dup;
	int		i;

	dup = (t_dot ***)malloc(sizeof(t_dot **) * fdf_dot_map_size(map));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup[i] = ft_arrdup(map[i]);
		if (dup[i] == NULL)
		{
			fdf_dot_map_delete_n(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static 	t_dot	**ft_arrdup(t_dot **arr)
{
	t_dot	**dup;
	int		i;

	dup = (t_dot **)malloc(sizeof(t_dot *) * fdf_dot_arr_size(arr));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_dotdup(arr[i]);
		if (dup[i] == NULL)
		{
			fdf_dot_arr_delete_n(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
