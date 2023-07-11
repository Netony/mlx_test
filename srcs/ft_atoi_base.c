/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:37:38 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 15:23:50 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"

#define HEXA_UPPER "0123456789ABCDEF"
#define HEXA_LOWER "0123456789abcdef"
#define DECIMAL "0123456789"

static long	ft_make_number(long nbr, int new, int radix);
static int	ft_ctoi_base(int c, const char *base);
static long	ft_strtol_base(int sign, const char *nptr, const char *base);
static int	ft_issign(int c);

int	ft_atoi_base(const char *nptr)
{
	int				sign;
	unsigned int	upper;
	unsigned int	lower;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
	{
		sign = ft_issign(*nptr);
		nptr++;
	}
	else if (ft_strncmp(nptr, "0x", 2) == 0)
	{
		nptr += 2;
		upper = ft_strtol_base(1, nptr, HEXA_UPPER);
		lower = ft_strtol_base(1, nptr, HEXA_LOWER);
		if (upper > lower)
			return (upper);
		else
			return (lower);
	}
	return (ft_strtol_base(sign, nptr, DECIMAL));
}

static long	ft_strtol_base(int sign, const char *nptr, const char *base)
{
	long	nbr;
	int		new;
	int		radix;

	radix = ft_strlen(base);
	if (radix < 2)
		return (-1);
	nbr = 0;
	while (ft_isin(*nptr, base))
	{
		new = ft_ctoi_base(*nptr, base);
		nbr = ft_make_number(nbr, sign * new, radix);
		nptr++;
	}
	return (nbr);
}

static long	ft_make_number(long nbr, int new, int radix)
{
	long	temp;
	long	check_nbr;
	int		check_new;

	temp = nbr * radix + new;
	check_nbr = temp / radix;
	check_new = temp % radix;
	if (check_nbr == nbr && check_new == new)
		return (temp);
	else if (nbr > 0)
		return (-1);
	else
		return (0);
}

static int	ft_ctoi_base(int c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_issign(int c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}
