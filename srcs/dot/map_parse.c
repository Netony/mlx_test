/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:07:27 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 12:26:27 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"
#include "fdf_utils.h"
#include <stdlib.h>

static t_dot	**dot_parse_array(char **s, int i, int weight);
static t_dot	*dot_parse(char *s, int i, int j, int weight);

t_dot	***map_parse(char ***tab, int weight)
{
	t_dot	***map;
	int		i;

	map = (t_dot ***)malloc(sizeof(t_dot **) * (ft_tabsize(tab) + 1));
	i = 0;
	while (tab[i])
	{
		map[i] = dot_parse_array(tab[i], i, weight);
		if (map[i] == NULL)
		{
			dot_mapdel_n(map, i);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

static t_dot	*dot_parse(char *s, int i, int j, int weight)
{
	int				z;
	unsigned int	color;

	s += ft_duplen(s, "-+");
	if (ft_duplen(s, "0123456789") > 0)
		z = ft_atoi_base(s);
	s += ft_duplen(s, "0123456789");
	if (ft_duplen(s, ",") == 1)
	{
		s += ft_duplen(s, ", ");
		if (ft_strncmp(s, "0x", 2) == 0)
			c = ft_atoi_base(s);
	}
	else
		c = 0x00FFFFFF;
	return (ft_dotnew(i * weight, j * weight, z, c));
}

static t_dot	**dot_parse_array(char **s, int i, int weight)
{
	t_dot	**array;
	int		j;

	array = (t_dot **)malloc(sizeof(t_dot *) * (ft_sptsize(s) + 1));
	j = 0;
	while (s[j])
	{
		array[j] = dot_parse(s[j], i, j, weight);
		if (array[j] == NULL)
		{
			dot_arrdel_n(array, j);
			return (NULL);
		}
		j++;
	}
	array[j] = NULL;
	return (array);
}
