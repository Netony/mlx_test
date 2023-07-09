/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:21:23 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 19:21:37 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_doterr_arr(t_dot **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

void	ft_doterr_tab(t_dot ***tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_dotdel_arr(tab[i++]);
	free(tab);
}

void	ft_dotdel_arr(t_dot **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_dotdel_tab(t_dot ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_dotdel_arr(tab[i++]);
	free(tab);
}

