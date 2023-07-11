/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:15:11 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 15:55:53 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"
#include <stdlib.h>

static int		dot_arr_get_size(t_dot **arr);
static t_dot	*ft_dotdup(t_dot *dot);
static t_dot	**ft_arrdup(t_dot **arr);

t_dot	***ft_mapdup(t_dot ***map)
{
	t_dot	***dup;
	int		i;

	dup = (t_dot ***)malloc(sizeof(t_dot **) * (map_get_row_size(map) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup[i] = ft_arrdup(map[i]);
		if (dup[i] == NULL)
		{
			dot_mapdel_n(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static t_dot	*ft_dotdup(t_dot *dot)
{
	t_dot	*dup;

	dup = dot_new(dot->x, dot->y, dot->z, dot->color);
	return (dup);
}

static t_dot	**ft_arrdup(t_dot **arr)
{
	t_dot	**dup;
	int		i;

	dup = (t_dot **)malloc(sizeof(t_dot *) * (dot_arr_get_size(arr) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_dotdup(arr[i]);
		if (dup[i] == NULL)
		{
			dot_arrdel_n(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static int	dot_arr_get_size(t_dot **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
