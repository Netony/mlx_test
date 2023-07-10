/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:23:18 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 18:25:05 by dajeon           ###   ########.fr       */
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

void	print(void *s)
{
	static int	i;

	printf("s[%02d]: %s", i++, s);
}

void	ft_lstprint(t_list *lst)
{
	ft_lstiter(lst, print);
}

void	ft_sptprint(char **spt)
{
	while (*spt)
		print(*(spt++));
}

void	ft_tabprint(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%2s", tab[i][j]);
			j++;
		}
		i++;
	}
}
