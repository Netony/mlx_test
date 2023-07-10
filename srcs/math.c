/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:14:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 12:32:17 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	larger(int x, int y)
{
	if (abs(x) >= abs(y))
		return (x);
	else
		return (y);
}

int	abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	iofn(int a, int b, int i, int n)
{
	int	x;

	x = a + (b - a) * i / n;
	return (x);
}

