/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_oper2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:30:00 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:33:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dup_sum(t_dot ***dup, t_dot *center)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_sum(dup[i][j], center);
			j++;
		}
		i++;
	}
}

void	dup_sub(t_dot ***dup, t_dot *center)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			dot_sub(dup[i][j], center);
			j++;
		}
		i++;
	}
}
