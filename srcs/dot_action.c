/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:56:15 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:52:59 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_action(t_dot ***map, void (*f)(t_dot *, int, int), int x, int y)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			f(map[i][j], x, y);
			j++;
		}
		i++;
	}
}

void	fdf_move(t_dot *dot, int x, int y)
{
	dot->x += x;
	dot->y += y;
}
