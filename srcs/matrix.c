/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:05:02 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 13:54:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**dot_to_matrix(t_dot *dot)
{
	int	**matrix;
	int	i;
	
	matrix = (int **)malloc(sizeof(int *) * 3);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		matrix[i] = (int *)malloc(sizeof(int) * 1);
		if (matrix[i] == NULL)
		{
			matrix_del(matrix, i);
			return (NULL);
		}
		i++;
	}
	matrix[1][0] = dot->x;
	matrix[2][0] = dot->y;
	matrix[3][0] = dot->z;
	return (matrix);
}

void	matrix_del(int **matrix, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(matrix[i++]);
	free(matrix);
}

t_dot	*matrix_to_dot(int **matrix)
{
	
}
