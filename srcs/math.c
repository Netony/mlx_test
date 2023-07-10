/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:14:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 16:42:10 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_larger(int x, int y)
{
	if (x > y)
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

int	ft_iofn(int a, int b, int i, int n)
{
	int	x;

	x = a + (b - a) * i / n;
	return (x);
}
