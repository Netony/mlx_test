/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 21:48:16 by dajeon           ###   ########.fr       */
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
}	t_vars;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		row;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_dot
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_dot;

typedef struct	s_map
{
	t_dot	***dots;
	int		row;
	int		col;
}	t_map;

// image.c
void	fdf_pixel_put(t_img *img, int x, int y, int color);
int		fdf_image_init(t_vars *vars, t_img *img);

//test
int		ft_lstadd(t_list **lst, void *content);
t_list	*get_line_list(int fd);
char	**list_to_chrp(t_list *line);
char	***arr_split(char **arr);

void	ft_lstprint(t_list *lst);
void	ft_sptprint(char **spt);
void	ft_tabprint(char ***tab);

void	ft_lstdclear(t_list **lst);
	
int		ft_tabsize(char ***tab);
int		ft_sptsize(char **spt);

void	ft_tabdel(char ***tab);
void	ft_sptdel(char **spt);

void	ft_taberr(char ***tab, int n);

int		ft_tab_rowsize(char ***tab);
int		ft_tab_colsize(char ***tab);

int		ft_toklen(const char *s, const char *set);
int		ft_duplen(const char *s, const char *set);
int		ft_nextlen(const char *s, const char *set);
int		ft_nextptr(const char *s, const char *set);

int		ft_atoi_new(char *nptr);
int		ft_atoi_base(const char *nptr, const char *base);

t_dot	*ft_dotnew(int x, int y, int z, int color);
void	ft_dotprint(t_dot *dot);

t_dot	*str_to_dot(int i, int j, char *s);
t_dot	**x_to_row(t_map *map, int i, char **x);
t_dot	***tab_to_map(t_map *map, char ***tab);

void	ft_mapdel(t_dot ***map, int m, int n);
void	ft_rowdel(t_dot **row, int n);

t_map	*ft_mapnew(t_dot ***dots, int row, int col);
#endif

/*
// map, row, dot
void	ft_mapdel(t_dot ***map, int row);
void	ft_rowdel(t_dot **row, int col);

// parse
t_list	*line_list(int fd);
t_list	*line_to_split(t_list *line);
t_dot	***make_map(t_list *list);
t_dot	**make_row(t_list *node, int y);
t_dot	*make_dot(char *s, int row, int col);


*/
