/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:22:36 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 13:54:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"

t_list	*get_line_list(int fd)
{
	t_list	*line;
	t_list	*cut;
	char	*buf;

	line = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (ft_lstadd_ret(&line, buf) < 0)
		{
			ft_lstclear(&line, free);
			return (NULL);
		}
	}
	cut = ft_lstmap(line, (void *(*)(void *))ft_cut_newline, free);
	ft_lstclear(&line, free);
	return (cut);
}

char	**list_to_array(t_list *line)
{
	int		n;
	int		i;
	char	**array;

	n = ft_lstsize(line);
	i = 0;
	array = (char **)malloc(sizeof(char *) * (n + 1));
	if (array == NULL)
		return (NULL);
	while (i < n)
	{
		array[i++] = line->content;
		line = line->next;
	}
	array[i] = NULL;
	return (array);
}

char	***array_split(char **arr, char c)
{
	int		i;
	char	***tab;

	i = 0;
	tab = (char ***)malloc(sizeof(char **) * (ft_sptsize(arr) + 1));
	if (tab == NULL)
		return (NULL);
	while (arr[i])
	{
		tab[i] = ft_split(arr[i], c);
		if (tab[i] == NULL)
		{
			ft_taberr(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
