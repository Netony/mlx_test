/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:20:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 19:20:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_dotprint(t_dot *dot, int i, int j)
{
	printf("dot[%d][%d]: ", i, j);
	printf("x: %d, ", dot->x);
	printf("y: %d, ", dot->y);
	printf("z: %d, ", dot->z);
	printf("color: %x\n", dot->color);
}

void	ft_dotprint_tab(t_dot ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_dotprint_arr(tab[i], i);
		i++;
	}
}

void	ft_dotprint_arr(t_dot **arr, int i)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		ft_dotprint(arr[j], i, j);
		j++;
	}
}

