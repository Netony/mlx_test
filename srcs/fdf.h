/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 17:43:30 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/incs/libft.h"
# include <mlx.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		row;
	int		bpp;
	int		endian;
}	t_img;

// image.c
void	fdf_pixel_put(t_img *img, int x, int y, int color);
int		fdf_image_init(t_vars *vars, t_img *img);

// map, row, dot
void	ft_mapdel(t_dot ***map, int row);
void	ft_rowdel(t_dot **row, int col);

// parse
t_list	*line_list(int fd);
t_list	*line_to_split(t_list *line);
t_dot	***make_map(t_list *list);
t_dot	**make_row(t_list *node, int y);
t_dot	*make_dot(char *s, int row, int col);


#endif
