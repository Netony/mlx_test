/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 22:29:07 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/incs/libft.h"
# include <stdio.h>
# include <mlx.h>


typedef struct s_dot
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_dot;

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

// fdf_dup_oper
void	dup_translate(t_dot ***dup, int x, int y);
void	dup_rotate(t_dot ***dup, double a, double b, double c);
void	dup_zoom(t_dot ***dup, int p);
void	dot_sum(t_dot *a, t_dot *b);
void	dot_sub(t_dot *a, t_dot *b);

void	dot_translate(t_dot *dot, int x, int y);
void	dot_zoom(t_dot *dot, t_dot *center, int p);
void	dot_rotate(t_dot *dot, double a, double b, double c);

// fdf_dot_oper
void	dot_add(t_dot *dot, int x, int y, int z);
void	dot_transform(t_dot *dot, double **matrix);
void	dot_iofn(t_dot *center, t_dot *dot, int i, int n);
void	dot_sum(t_dot *a, t_dot *b);
void	dot_sub(t_dot *a, t_dot *b);

// fdf_matrix
double	**ft_matrix_new(double *row, int m, int n);
void	ft_matrix_del(double **matrix, int m, int n);

// fdf_dot_math
int	dot_larger_size(t_dot *d1, t_dot *d2);

// FDF_image
t_img	*fdf_image_init(t_vars *vars);
void	fdf_image_set(t_img *img, int x, int y, int color);
int		fdf_image_set_check(int x, int y);
void	fdf_image_destroy(t_vars *vars, t_img *img);

// FDF_image_set_dot
void	fdf_image_set_dot(t_img *img, t_dot *dot);
void	fdf_image_set_line(t_img *img, t_dot *d1, t_dot *d2);
void	fdf_image_set_map(t_img *img, t_dot ***dup);

// FDF_math
int		ft_larger(int x, int y);
int		ft_abs(int n);
int		ft_iofn(int a, int b, int i, int n);

// FDF_map
t_dot	*ft_map_center(t_dot ***map);

// fdf_dot_new
t_dot	*ft_dotnew(int x, int y, int z, int color);
t_dot	*fdf_dot_parse(char *s, int i, int j, int weight);
t_dot	***fdf_dot_parse_map(char ***s, int weight);

// FDF_dot_delete
void	fdf_dot_arr_delete(t_dot **arr);
void	fdf_dot_arr_delete_n(t_dot **arr, int n);
void	fdf_dot_map_delete(t_dot ***map);
void	fdf_dot_map_delete_n(t_dot ***map, int n);

// FDF_dot_size
int		fdf_dot_arr_size(t_dot **arr);
int		fdf_dot_map_size(t_dot ***map);
int		fdf_dot_map_row_size(t_dot ***map);
int		fdf_dot_map_col_size(t_dot ***map);

// FDF_put
void	fdf_putmap(t_vars *vars, t_dot ***map);

// ft_dup
t_dot	*ft_dotdup(t_dot *dot);
t_dot	***ft_mapdup(t_dot ***map);

void	ft_lstclear_clean(t_list **lst);

int		ft_tabsize(char ***tab);
int		ft_sptsize(char **spt);

void	ft_tabdel(char ***tab);
void	ft_sptdel(char **spt);

int		ft_toklen(const char *s, const char *set);
int		ft_duplen(const char *s, const char *set);
int		ft_nextlen(const char *s, const char *set);
int		ft_nextptr(const char *s, const char *set);

int		ft_atoi_new(char *nptr);
int		ft_atoi_base(const char *nptr, const char *base);

// dot_new, dot_make

// tab.c
int		ft_tabsize(char ***tab);
int		ft_tabcheck(char ***tab);

void	ft_taberr(char ***tab, int n);

char	*ft_cut_line(char *line);
int		ft_lstadd(t_list **lst, void *content);
t_list	*get_line_list(int fd);
char	***array_to_tab(char **arr);
char	**list_to_array(t_list *line);

// fdf
t_dot	***fdf_map_parse(char *filepath);
void	fdf_hook(t_vars *vars);
void	fdf_close(t_vars *vars);

// TEST
void	ft_lstprint(t_list *lst);
void	ft_sptprint(char **spt);
void	ft_tabprint(char ***tab);
void	ft_dotprint_tab(t_dot ***tab);
void	ft_dotprint_arr(t_dot **arr, int i);
void	ft_dotprint(t_dot *dot, int i, int j);

#endif
