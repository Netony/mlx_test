/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:23:42 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 07:24:21 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*dot_parse_one(char *s, int i, int j, int weight)
{
	int		z;
	int		c;

	z = ft_atoi(s);
	c = ft_atoi_new(s + ft_nextptr(s, ", "));
	return (ft_dotnew(i * weight, j * weight, z, c));
}

t_dot	**dot_parse_array(char **s, int i, int weight)
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
			ft_doterr_arr(array, j);
			return (NULL);
		}
		j++;
	}
	array[j] = NULL;
	return (array);
}

t_dot	***dot_parse_table(char ***s, int weight)
{
	t_dot	***table;
	int		i;

	table = (t_dot ***)malloc(sizeof(t_dot **) * (ft_tabsize(s) + 1));
	i = 0;
	while (s[i])
	{
		table[i] = dot_parse_array(s[i], i, weight);
		if (table[i] == NULL)
		{
			ft_doterr_tab(table, i);
			return (NULL);
		}
		i++;
	}
	table[i] = NULL;
	return (table);
}
