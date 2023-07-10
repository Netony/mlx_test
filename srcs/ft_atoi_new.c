/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:45:42 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 21:17:39 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_atoi_base(const char *nptr, const char *base);
// static unsigned int	atoi_larger(unsigned int a, unsigned int b);

int	ft_atoi_new(char *nptr)
{
	int	atoi;

	while (ft_isspace(*nptr))
		nptr++;
	if (ft_strncmp(nptr, "0x", 2) == 0)
	{
		nptr += 2;
		atoi = ft_larger( \
				ft_atoi_base(nptr, "0123456789abcdef"), \
				ft_atoi_base(nptr, "0123456789ABCDEF"));
	}
	else
		atoi = ft_atoi(nptr);
	return (atoi);
}

/*
static unsigned int	atoi_larger(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
*/
