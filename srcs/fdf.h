/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:21:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:53:00 by dajeon           ###   ########.fr       */
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
char	***parse_table(int fd);
t_dot	***parse_map(char ***s, int weight);
char	*ft_cut_line(char *line);
int		ft_lstadd(t_list **lst, void *content);
t_list	*get_line_list(int fd);
char	***array_to_tab(char **arr);
char	**list_to_array(t_list *line);

void	ft_lstprint(t_list *lst);
void	ft_sptprint(char **spt);
void	ft_tabprint(char ***tab);

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


t_dot	*str_to_dot(int i, int j, char *s);

void	ft_rowdel(t_dot **row, int n);

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

// tab.c
int		ft_tabsize(char ***tab);
int		ft_tabcheck(char ***tab);

void	ft_taberr(char ***tab, int n);
#endif

/*
void	ft_rowdel(t_dot **row, int col);

// parse
t_list	*line_list(int fd);
t_list	*line_to_split(t_list *line);
t_dot	**make_row(t_list *node, int y);
t_dot	*make_dot(char *s, int row, int col);


*/
