/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dot_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:42:22 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 21:32:20 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_translate(t_dot *dot, int x, int y)
{
	dot->x += x;
	dot->y += y;
}

void	dot_zoom(t_dot *dot, t_dot *center, int p)
{
	dot_iofn(center, dot, p, 100);
}
