/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:02:56 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/11 16:11:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	error_argument(void)
{
	errno = EINVAL;
	perror("fdf");
	exit(-1);
}

void	error_errno(void)
{
	perror("fdf");
	exit(-1);
}
