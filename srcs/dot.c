/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:01:37 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 21:24:22 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*ft_dotnew(int x, int y, int z, int color)
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

void	ft_dotprint(t_dot *dot)
{
	printf("x: %d\n", dot->x);
	printf("y: %d\n", dot->y);
	printf("z: %d\n", dot->z);
	printf("color: %x\n", dot->color);
}

void	ft_rowdel(t_dot **row, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(row[i++]);
	free(row);
}

void	ft_mapdel(t_dot ***map, int m, int n)
{
	int	i;

	i = 0;
	while (i < m)
		ft_rowdel(map[i++], n);
	free(map);
}

t_dot	***tab_to_map(t_map *map, char ***tab)
{
	t_dot	***dots;
	int		i;

	dots = (t_dot ***)malloc(sizeof(t_dot **) * map->row);
	i = 0;
	while (i < map->row)
	{
		dots[i] = x_to_row(map, i, tab[i]);
		if (dots[i] == NULL)
		{
			ft_mapdel(dots, i, map->col);
			return (NULL);
		}
		i++;
	}
	return (dots);
}

t_dot	**x_to_row(t_map *map, int i, char **x)
{
	t_dot	**row;
	int		j;

	row = (t_dot **)malloc(sizeof(t_dot *) * map->col);
	j = 0;
	while (j < map->col)
	{
		row[j] = str_to_dot(i, j, x[j]);
		if (row[j] == NULL)
		{
			ft_rowdel(row, j);
			return (NULL);
		}
		j++;
	}
	return (row);
}

t_dot	*str_to_dot(int i, int j, char *s)
{
	t_dot	*dot;
	int		z;
	int		c;

	z = ft_atoi(s);
	c = ft_atoi_new(s + ft_nextptr(s, ", "));
	dot = ft_dotnew(i, j, z, c);
	return (dot);
}
