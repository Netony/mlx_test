/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_rough.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:46:11 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/08 15:59:28 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

t_dot	***parser_rough(int fd)
{
	t_dot	***dot;
}

t_list	*line_list(int fd)
{
	char	*line;
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new = ft_lstnew(line);
		if (new == NULL)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
	}
	close(fd);
	return (lst);
}

t_list	*line_to_split(t_list *line)
{
	list	*split;

	split = ft_lstmap(line, split_by_space, ft_sptdel);
	ft_lstclear(line, free);
	return (split);
}

t_dot	***make_map(t_list *list)
{
	
}

t_dot	**make_row(t_list *node, int y)
{
	t_dot	**row;
	t_dot	*dot;
	char	**split;
	int		x;
	int		n;

	split = node->content;
	x = 0;
	n = ft_sptsize(split);
	row = (t_dot **)malloc(sizeof(t_dot *) * n);
	if (row == NULL)
		return (NULL);
	while (x < n)
	{
		dot = make_dot(split[x++], y, x);
		if (dot == NULL)
		{
			free(row);
			return (NULL);
		}
	}
}

t_dot	*make_dot(char *s, int row, int col)
{
	int		n;
	int		color;
	char	**spt;
	t_dot	*dot;

	spt = ft_split(s, ',');
	color = 0;
	if (spt)
	{
		n = ft_atoi(spt[0]);
		if (ft_sptsize(spt) == 2)
			color = ft_atoi_base(spt[1]);
		dot = ft_dotnew(col, row, n, color);
		ft_sptdel(spt);
	}
	else
		return (NULL);
	return (dot);
}

char	**split_by_space(const char *s)
{
	return(ft_split(s, ' '));
}
