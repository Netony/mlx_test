/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:23:25 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 18:29:23 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	iofn(int a, int b, int i, int n);
#include <math.h>

int	number_zoom(int center, int n, int percent)
{
	int	zoom;

	zoom = iofn(center, n, percent, 100);
	return (zoom);
}

int	number_move(int n, int m)
{
	return (n + x);
}

int	**

int	x_yaw(int x, int y, int z, int a)
{
	double	ret;

	ret = cos(a) * x + (-sin(a) * y);
	return (ret);
}

int	y_yaw(int x, int y, int z, int a)
{
	double	ret;

	ret = sin(a) * x + cos(a) * y;
	return (ret);
}

int	x_pitch(int x, int y, int z, int b)
{
	double	ret;

	ret = cos(b) * x + sin(b) * z;
	return (ret);
}

int	y_pitch(int x, int y, int z, int b)
{
	return (y);
}

int	x_roll(int x, int y, int z, int g)
{
	return (x);
}

int	y_roll(int x, int y, int z, int g)
{
	double	ret;

	ret = cos(g) * y + (-sin(g) * z);
	return (ret);
}

t_dot	*ft_map_center(t_dot ***map)
{
	int	i;
	int	j;

	i = ft_maprow(map);
	j = ft_mapcol(map);
	return (map[i][j]);
}
