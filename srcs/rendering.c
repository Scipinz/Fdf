/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:14:31 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/07 12:57:40 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	diag(t_instance *fdf)
{
	return (sqrt(pow(fdf->map.width, 2) + \
	pow(fdf->map.height, 2)) * fdf->grid.size);
}

static void	grid_check(t_instance *fdf)
{
	while (diag(fdf) + sin(0.5) * (HEIGHT / 2) > HEIGHT)
		fdf->grid.size -= 1;
	while (diag(fdf) - fdf->grid.y + (HEIGHT / 2) > HEIGHT)
		fdf->grid.y += 20;
}

static double	set_height(t_map map)
{
	double	diff;
	double	height;

	height = 1.0;
	diff = ft_max(map.point, map.height * map.width) - \
	ft_min(map.point, map.height * map.width);
	while (diff > 10)
	{
		diff *= 0.5;
		height *= 0.65;
	}
	return (height);
}

static void	param(t_instance *fdf)
{
	fdf->grid.size = 50;
	fdf->grid.x = 0;
	fdf->grid.y = 0;
	fdf->grid.height = set_height(fdf->map);
	fdf->grid.z = 10 * fdf->grid.height;
}

void	init_grid(t_instance *fdf)
{
	param(fdf);
	grid_check(fdf);
}
