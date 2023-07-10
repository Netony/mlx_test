/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:20:12 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 18:25:06 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tabsize(char ***tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	ft_sptsize(char **spt)
{
	int	size;

	size = 0;
	while (spt[size])
		spt[size++];
	return (size);
}

int	ft_tabcheck(char ***tab)
{
	int	i;
	int	size;
	int	check;

	i = 0;
	while (tab[i])
	{
		size = ft_sptsize(tab[i]);
		if (i == 0)
			check = size;
		else
		{
			if (check != size)
				return (-1);
		}
		i++;
	}
	return (size);
}
