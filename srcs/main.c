/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 15:22:27 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/03 12:24:45 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_instance	fdf;

	if (argc != 2)
		error("Invalid map input");
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!fdf.mlx)
		return (0);
	if (fdf.mlx)
	{
		fdf.map = map_parse(argv[1]);
		init_grid(&fdf);
		fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
		if (!fdf.img)
		{
			free(fdf.map.point);
			error("Image generation failed!");
		}
		project_map(fdf);
		mlx_loop(fdf.mlx);
	}
	else
		error("Initializing fdf failed");
	mlx_terminate(fdf.mlx);
	free (fdf.map.point);
	exit(EXIT_SUCCESS);
}
