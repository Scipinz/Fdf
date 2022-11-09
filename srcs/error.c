/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:08:48 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/08 11:47:22 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	error(char *error_msg)
// {
// 	if (errno)
// 		perror("ERROR");
// 	else
// 		ft_putendl_fd(error_msg, STDERR_FILENO);
// 	exit(EXIT_FAILURE);
// }

void	error(char *str, int exit_code)
{
	ft_putendl_fd(str, 2);
	exit(exit_code);
}
