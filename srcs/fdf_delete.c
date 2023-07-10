/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:17:09 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 18:25:07 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_lstclear_clean(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
