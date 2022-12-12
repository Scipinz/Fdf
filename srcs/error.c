/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:08:48 by kblok         #+#    #+#                 */
/*   Updated: 2022/12/12 15:30:52 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str, int exit_code, mlx_t *mlx)
{
	ft_putendl_fd(str, 2);
	if (mlx != 0)
		mlx_terminate(mlx);
	exit(exit_code);
}
