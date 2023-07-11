/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 11:48:30 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/incs/libft.h"
# include <stdio.h>
# include <mlx.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_dot	***map;
}	t_vars;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		row;
	int		bpp;
	int		endian;
}	t_img;

// FDF_image
t_img	*fdf_image_init(t_vars *vars);
void	fdf_image_set(t_img *img, int x, int y, int color);
int		fdf_image_set_check(t_vars *vars, int x, int y);
void	fdf_image_destroy(t_vars *vars, t_img *img);

// FDF_image_set_dot
void	fdf_image_set_map(t_vars *vars, t_img *img, t_dot ***dup);
void	fdf_image_set_line(t_vars *vars, t_img *img, t_dot *d1, t_dot *d2);
void	fdf_image_set_dot(t_vars *vars, t_img *img, t_dot *dot);

// FDF_put
void	fdf_putmap(t_vars *vars, t_dot ***map);

void	ft_lstclear_clean(t_list **lst);

int		ft_tabsize(char ***tab);
int		ft_sptsize(char **spt);

void	ft_tabdel(char ***tab);
void	ft_sptdel(char **spt);

int		ft_toklen(const char *s, const char *set);
int		ft_duplen(const char *s, const char *set);
int		ft_nextlen(const char *s, const char *set);
int		ft_nextptr(const char *s, const char *set);
int		ft_atoi_base(const char *nptr);

// tab.c
int		ft_tabcheck(char ***tab);
void	ft_taberr(char ***tab, int n);

char	*ft_cut_line(char *line);
int		ft_lstadd(t_list **lst, void *content);
t_list	*get_line_list(int fd);
char	***array_to_tab(char **arr);
char	**list_to_array(t_list *line);

// hook
t_dot	***fdf_map_parse(char *filepath);
void	fdf_hook(t_vars *vars);

// TEST
void	ft_lstprint(t_list *lst);
void	ft_sptprint(char **spt);
void	ft_tabprint(char ***tab);
void	ft_dotprint_tab(t_dot ***tab);
void	ft_dotprint_arr(t_dot **arr, int i);
void	ft_dotprint(t_dot *dot, int i, int j);

#endif
