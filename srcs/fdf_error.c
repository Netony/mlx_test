/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:02:56 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 19:04:05 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	set_error_argument(void)
{
	errno = EINVAL;
}

void	error_exit(char *name)
{
	perror(name);
	exit(-1);
}
