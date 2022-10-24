/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyhooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 12:55:54 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/18 13:48:30 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hooks(void *param)
{
	t_instance	*fdf;

	fdf = (t_instance *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		mlx_terminate(fdf->mlx);
		free (fdf->map.point);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W) || \
		mlx_is_key_down(fdf->mlx, MLX_KEY_A) || \
		mlx_is_key_down(fdf->mlx, MLX_KEY_S) || \
		mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		location(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q) || \
		mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		zoom(fdf);
}
