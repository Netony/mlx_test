/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:27:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 15:00:39 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_larger(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	ft_smaller(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

double	ft_iofn(double a, double b, int i, int n)
{
	double	x;

	x = a + (b - a) * i / n;
	return (x);
}

int	ft_iofn_int(int a, int b, int i, int n)
{
	int	x;

	x = a + (b - a) * i / n;
	return (x);
}
