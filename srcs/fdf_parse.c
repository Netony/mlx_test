/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:19:46 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 16:09:02 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dot.h"
#include "fdf_utils.h"
#include "fdf.h"
#include <fcntl.h>

char	***parse_table(int fd);
int		parse_size_check(char ***tab);

t_dot	***fdf_map_parse(char *filepath, int weight)
{
	int		fd;
	char	***tab;
	t_dot	***map;

	fd = open(filepath, O_RDONLY);
	tab = parse_table(fd);
	if (tab == NULL)
		return (NULL);
	if (parse_size_check(tab) < 0)
		error_argument();
	map = map_parse(tab, weight);
	ft_tabdel(tab);
	close(fd);
	return (map);
}

char	***parse_table(int fd)
{
	t_list	*line;
	char	**arr;
	char	***tab;

	line = get_line_list(fd);
	if (line == NULL)
		return (NULL);
	arr = list_to_array(line);
	ft_lstclear_clean(&line);
	if (arr == NULL)
		return (NULL);
	tab = array_split(arr, ' ');
	ft_sptdel(arr);
	if (tab == NULL)
		return (NULL);
	return (tab);
}

int	parse_size_check(char ***tab)
{
	int	i;
	int	size;
	int	check;

	check = ft_sptsize(tab[0]);
	i = 0;
	while (tab[i])
	{
		size = ft_sptsize(tab[i]);
		if (check < 2 || check != size)
			return (-1);
		i++;
	}
	if (i < 2)
		return (-1);
	return (size);
}
