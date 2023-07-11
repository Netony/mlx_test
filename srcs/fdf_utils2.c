/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:03:26 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 17:04:38 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"

int	ft_lstadd_ret(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

char	*ft_cut_newline(char *s)
{
	return (ft_strtrim(s, "\n"));
}

void	ft_lstclear_clean(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

unsigned int	ft_color_iofn(unsigned int c1, unsigned int c2, int i, int n)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = ft_iofn((c1 >> 24) & 0xff, (c2 >> 24 & 0xff), i, n);
	r = ft_iofn((c1 >> 16) & 0xff, (c2 >> 16 & 0xff), i, n);
	g = ft_iofn((c1 >> 8) & 0xff, (c2 >> 8 & 0xff), i, n);
	b = ft_iofn((c1 >> 0) & 0xff, (c2 >> 0 & 0xff), i, n);
	return (t << 24 | r << 16 | g << 8 | b << 0);
}
