/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:23:54 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:43:33 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***parse_table(int fd)
{
	t_list	*line;
	char	**arr;
	char	***tab;

	line = get_line_list(fd);
	if (line == NULL)
		return (NULL);
	arr = list_to_array(line);
	ft_lstdclear(&line);
	if (arr == NULL)
		return (NULL);
	tab = array_to_tab(arr);
	ft_sptdel(arr);
	if (tab == NULL)
		return (NULL);
	return (tab);
}

int	ft_lstadd(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

t_list	*get_line_list(int fd)
{
	t_list	*line;
	char	*buf;
	char	*cut;

	line = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		cut = ft_strtrim(buf, "\n");
		free(buf);
		if (cut == NULL)
		{
			ft_lstclear(&line, free);
			return (NULL);
		}
		if (ft_lstadd(&line, cut) < 0)
		{
			ft_lstclear(&line, free);
			return (NULL);
		}
	}
	return (line);
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
