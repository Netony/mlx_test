/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:21:55 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:43:41 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_tabsize(char ***tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	ft_tabcheck(char ***tab)
{
	int	i;
	int	size;
	int	check;

	i = 0;
	while (tab[i])
	{
		size = ft_sptsize(tab[i]);
		if (i == 0)
			check = size;
		else
		{
			if (check != size)
				return (-1);
		}
		i++;
	}
	return (size);
}

char	***array_to_tab(char **arr)
{
	int		i;
	char	***tab;

	i = 0;
	tab = (char ***)malloc(sizeof(char **) * (ft_sptsize(arr) + 1));
	if (tab == NULL)
		return (NULL);
	while (arr[i])
	{
		tab[i] = ft_split(arr[i], ' ');
		if (tab[i] == NULL)
		{
			ft_taberr(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
