/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 17:09:08 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/incs/libft.h"
# include <stdio.h>
# include <mlx.h>
# include "dot.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_dot	***map;
	t_dot	***origin;
}	t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		row;
	int		bpp;
	int		endian;
}	t_img;

t_img	*fdf_image_init(t_vars *vars);
void	fdf_image_set(t_img *img, int x, int y, int color);
int		fdf_image_set_check(t_vars *vars, int x, int y);
void	fdf_image_destroy(t_vars *vars, t_img *img);

void	error_argument(void);
void	error_errno(void);

int		fdf_put_start(t_vars *vars);
void	fdf_put_isometric(t_vars *vars);
void	fdf_put_oblique(t_vars *vars);

void	fdf_image_set_map(t_vars *vars, t_img *img, t_dot ***dup);
void	fdf_putmap(t_vars *vars, t_dot ***map);

t_dot	***fdf_map_parse(char *filepath, int weight);

void	fdf_hook(t_vars *vars);

void	ft_lstprint(t_list *lst);
void	ft_sptprint(char **spt);
void	ft_tabprint(char ***tab);
void	ft_dotprint_tab(t_dot ***tab);
void	ft_dotprint_arr(t_dot **arr, int i);
void	ft_dotprint(t_dot *dot, int i, int j);

#endif
