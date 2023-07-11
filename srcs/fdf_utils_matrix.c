/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:33:19 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 10:20:41 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	ft_matrix_del(double **matrix, int m, int n);

double	**ft_matrix_new(double *row, int m, int n)
{
	int		i;
	int		j;
	double	**matrix;

	matrix = (double **)malloc(sizeof(double *) * m);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < m)
	{
		j = 0;
		matrix[i] = (double *)malloc(sizeof(double) * n);
		if (matrix[i] == NULL)
		{
			ft_matrix_del(matrix, i, n);
			return (NULL);
		}
		while (j < n)
		{
			matrix[i][j] = *(row++);
			j++;
		}
		i++;
	}
	return (matrix);
}

void	ft_matrix_del(double **matrix, int m, int n)
{
	int	i;

	(void)n;
	i = 0;
	while (i < m)
		free(matrix[i++]);
	free(matrix);
}
