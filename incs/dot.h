/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:04:25 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 16:56:13 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOT_H
# define DOT_H

typedef struct s_dot
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}	t_dot;

void	dot_add(t_dot *dot, int x, int y, int z);
void	dot_trans(t_dot *dot, double **matrix);
void	dot_scalar_p(t_dot *dot, int p);
void	dot_rotate(t_dot *dot, double a, double b, double c);

t_dot	*dot_new(int x, int y, int z, int color);
void	dot_arrdel_n(t_dot **arr, int n);
void	dot_mapdel_n(t_dot ***map, int n);
void	dot_arrdel(t_dot **arr);
void	dot_mapdel(t_dot ***map);

t_dot	***map_parse(char ***tab, int weight);

int		map_get_x_center(t_dot ***map);
int		map_get_y_center(t_dot ***map);
int		map_get_z_center(t_dot ***map);
int		map_get_row_size(t_dot ***map);
int		map_get_col_size(t_dot ***map);

void	map_translate(t_dot ***map, int x, int y, int z);
void	map_rotate(t_dot ***map, double a, double b, double c);
void	map_zoom(t_dot ***map, int p);

t_dot	***ft_mapdup(t_dot ***map);

void	map_highlight(t_dot ***map, unsigned int color, int weight);

#endif
