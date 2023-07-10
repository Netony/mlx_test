/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:13:18 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 19:23:43 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	dot_larger_size(t_dot *d1, t_dot *d2)
{
	int	dx;
	int	dy;

	dx = d1->x - d2->x;
	dy = d1->y - d2->y;
	return (ft_larger(ft_abs(dx), ft_abs(dy)));
}
