/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/10 16:10:12 by dajeon           ###   ########.fr       */
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
	t_dot	***map;
	int		width;
	int		height;
}	t_vars;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		row;
	int		bpp;
	int		endian;
}	t_img;

// Matrix
int		**dot_to_matrix(t_dot *dot);
void	matrix_del(int **matrix, int row);

// Action
void	map_action(t_dot ***map, void (*f)(t_dot *, int, int), int x, int y);
void	fdf_move(t_dot *dot, int x, int y);

// fdf
void	fdf_hook(t_vars *vars);
void	fdf_close(t_vars *vars);
t_dot	***fdf_parse(char *filepath);

// image.c
t_img	*fdf_image_init(t_vars *vars);
void	fdf_image_set(t_img *img, int x, int y, int color);
void	fdf_image_destroy(t_vars *vars, t_img *img);

void	fdf_putmap(t_vars *vars, t_dot ***map);

// testparse.c
char	***fdf_parse(int fd);
t_dot	*dot_parse_one(char *s, int i, int j, int weight);
t_dot	***dot_parse_table(char ***s, int weight);

// Map
t_dot	***ft_tabdup(t_dot ***tab);
t_dot	**ft_arrdup(t_dot **arr);

char	*ft_cut_line(char *line);
int		ft_lstadd(t_list **lst, void *content);
t_list	*get_line_list(int fd);
char	***array_to_tab(char **arr);
char	**list_to_array(t_list *line);

void	ft_lstprint(t_list *lst);
void	ft_sptprint(char **spt);
void	ft_tabprint(char ***tab);

int		ft_arrsize(t_dot **arr);
int		ft_tabsize(t_dot ***tab);

void	ft_lstdclear(t_list **lst);
	
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

// dot_print
void	ft_dotprint_tab(t_dot ***tab);
void	ft_dotprint_arr(t_dot **arr, int i);
void	ft_dotprint(t_dot *dot, int i, int j);

// dot_error
void	ft_dotdel_arr(t_dot **arr);
void	ft_dotdel_tab(t_dot ***tab);
void	ft_doterr_tab(t_dot ***tab, int n);
void	ft_doterr_arr(t_dot **arr, int n);

// dot_new, dot_make
t_dot	*ft_dotnew(int x, int y, int z, int color);
t_dot	*ft_dotdup(t_dot *dot);

// tab.c
int		ft_tabsize(char ***tab);
int		ft_tabcheck(char ***tab);

void	ft_taberr(char ***tab, int n);

int		ft_mapcol(t_dot	***map);
int		ft_maprow(t_dot ***map);
#endif
