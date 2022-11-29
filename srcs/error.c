/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:08:48 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/29 13:03:34 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str, int exit_code)
{
	ft_putendl_fd(str, 2);
	exit(exit_code);
}
