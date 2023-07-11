/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:09:32 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 11:11:19 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

// fdf_matrix
double	**ft_matrix_new(double *row, int m, int n);
void	ft_matrix_del(double **matrix, int m, int n);

// FDF_math
int		ft_larger(int x, int y);
int		ft_smaller(int x, int y);
int		ft_abs(int n);
int		ft_iofn(int a, int b, int i, int n);

#endif
