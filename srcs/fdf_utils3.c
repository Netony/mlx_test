/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:17:09 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 13:34:46 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_taberr(char ***tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}

void	ft_sptdel(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
	{
		free(spt[i]);
		i++;
	}
	free(spt);
}

void	ft_tabdel(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_sptdel(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_tabsize(char ***tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	ft_sptsize(char **spt)
{
	int	size;

	size = 0;
	while (spt[size])
		size++;
	return (size);
}
