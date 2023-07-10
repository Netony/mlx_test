/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:01:37 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 13:56:57 by dajeon           ###   ########.fr       */
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
	if (color == 0)
		new->color = 0x00FFFFFF;
	else
		new->color = color;
	return (new);
}

t_dot	*ft_dotdup(t_dot *dot)
{
	t_dot	*dup;

	dup = ft_dotnew(dot->x, dot->y, dot->z, dot->color);
	return (dup);
}
