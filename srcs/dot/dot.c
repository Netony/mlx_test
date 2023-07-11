/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:07:31 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 12:26:28 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"
#include <stdlib.h>

t_dot	*dot_new(int x, int y, int z, int color)
{
	t_dot	*new;

	new = (t_dot *)malloc(sizeof(t_dot));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	return (new);
}

void	dot_arrdel_n(t_dot **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

void	dot_mapdel_n(t_dot ***map, int n)
{
	int	i;

	i = 0;
	while (i < n)
		dot_arrdel(map[i++]);
	free(map);
}

void	dot_arrdel(t_dot **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	dot_mapdel(t_dot ***map)
{
	int	i;

	i = 0;
	while (map[i])
		dot_arrdel(map[i++]);
	free(map);
}
