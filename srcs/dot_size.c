/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:16:05 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 16:16:45 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_arrsize(t_dot **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ft_tabsize(t_dot ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
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
