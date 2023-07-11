/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:09:32 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 15:21:23 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H
# include "../libft/incs/libft.h"
# include "dot.h"

double			**ft_matrix_new(double *row, int m, int n);
void			ft_matrix_del(double **matrix, int m, int n);

int				ft_larger(int x, int y);
int				ft_smaller(int x, int y);
int				ft_abs(int n);
double			ft_iofn(double a, double b, int i, int n);
int				ft_iofn_int(double a, double b, int i, int n);

double			degree_to_radian(double degree);

char			**list_to_array(t_list *line);
char			***array_split(char **arr, char c);
t_list			*get_line_list(int fd);

char			*ft_cut_newline(char *s);
int				ft_lstadd_ret(t_list **lst, void *content);
void			ft_lstclear_clean(t_list **lst);
unsigned int	ft_color_iofn(unsigned int c1, unsigned int c2, int i, int n);

void			ft_taberr(char ***tab, int n);
void			ft_sptdel(char **spt);
void			ft_tabdel(char ***tab);
int				ft_tabsize(char ***tab);
int				ft_sptsize(char **spt);

int				ft_toklen(const char *s, const char *set);
int				ft_duplen(const char *s, const char *set);
int				ft_nextlen(const char *s, const char *set);
int				ft_nextptr(const char *s, const char *set);

int				ft_atoi_base(const char *nptr);

#endif
