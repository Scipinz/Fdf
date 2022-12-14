/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 15:22:27 by kblok         #+#    #+#                 */
/*   Updated: 2022/12/12 13:39:40 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	t_instance	fdf;

	if (argc != 2)
		error("Invalid input", 1, 0);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!fdf.mlx)
		return (0);
	if (fdf.mlx)
	{
		fdf.map = parse(argv[1], fdf.mlx);
		init_grid(&fdf);
		fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
		if (!fdf.img)
		{
			free(fdf.map.point);
			error("Generating image failed!", 1, fdf.mlx);
		}
		projection(fdf);
		mlx_loop_hook(fdf.mlx, &hook, fdf.mlx);
		mlx_loop(fdf.mlx);
	}
	mlx_terminate(fdf.mlx);
	free (fdf.map.point);
	exit(EXIT_SUCCESS);
}
