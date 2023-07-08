/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:41:31 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 17:41:41 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_mapdel(t_dot ***map, int row)
{
	int	i;

	i = 0;
	while (i < row)
		ft_rowdel(row[i++]);
}

void	ft_rowdel(t_dot **row, int col)
{
	int	i;

	i = 0;
	while (i < col)
		free(row[i++]);
}
