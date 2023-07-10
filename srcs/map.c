/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:49:39 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 16:10:14 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	***ft_tabdup(t_dot ***tab)
{
	t_dot	***dup;
	int		i;

	dup = (t_dot ***)malloc(sizeof(t_dot **) * ft_tabsize(tab));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		dup[i] = ft_arrdup(tab[i]);
		if (dup[i] == NULL)
		{
			ft_doterr_tab(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

t_dot	**ft_arrdup(t_dot **arr)
{
	t_dot	**dup;
	int		i;

	dup = (t_dot **)malloc(sizeof(t_dot *) * ft_arrsize(arr));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_dotdup(arr[i]);
		if (dup[i] == NULL)
		{
			ft_doterr_arr(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int	ft_maprow(t_dot ***map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

int	ft_mapcol(t_dot	***map)
{
	int	col;

	col = 0;
	while (map[0][col])
		col++;
	return (col);
}
