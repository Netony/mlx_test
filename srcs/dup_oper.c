/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:28:20 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:33:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*dup_center(t_dot ***map);
void	dup_sub(t_dot ***dup, t_dot *center);
void	dup_sum(t_dot ***dup, t_dot *center);

void	dup_translate(t_dot ***dup, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_translate(dup[i][j], x, y);
			j++;
		}
		i++;
	}
}

void	dup_rotate(t_dot ***dup, double a, double b, double c)
{
	int		i;
	int		j;
	t_dot	*center;

	i = 0;
	center = dup_center(dup);
	//dup_sub(dup, center);
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_rotate(dup[i][j], a, b, c);
			j++;
		}
		i++;
	}
	//dup_sum(dup, center);
}

void	dup_zoom(t_dot ***dup, int p)
{
	t_dot	*center;
	int		i;
	int		j;

	center = dup_center(dup);
	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_zoom(dup[i][j], center, p);
			j++;
		}
		i++;
	}
}	

t_dot	*dup_center(t_dot ***map)
{
	int	i;
	int	j;

	i = fdf_dot_map_row_size(map) / 2;
	j = fdf_dot_map_col_size(map) / 2;
	return (map[i][j]);
}
