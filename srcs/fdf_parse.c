/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:19:46 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/09 21:32:16 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

t_dot	***fdf_parse(char *filepath)
{
	int		fd;
	char	***tab;
	t_dot	***map;

	fd = open(filepath, O_RDONLY);
	tab = parse_table(fd);
	if (tab == NULL)
		return (NULL);
	map = parse_map(tab, 10);
	close(fd);
	return (map);
}

void	fdf_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

