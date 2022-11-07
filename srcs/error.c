/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:08:48 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/24 17:19:10 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *error_msg)
{
	if (errno)
		perror("ERROR");
	else
		ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
