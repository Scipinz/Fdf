/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   projection.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:56:11 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/07 12:00:18 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calc_height(t_instance fdf, int x, int y)
{
	return (fdf.map.point[y * fdf.map.width + x] * fdf.grid.z);
}

static void	draw_grid(t_instance fdf, int x, int y)
{
	if (x != fdf.map.width - 1)
		draw_line(fdf.img, calc_coord(fdf, x, y, calc_height(fdf, x, y)), \
		calc_coord(fdf, x + 1, y, calc_height(fdf, x + 1, y)));
	if (y != fdf.map.height - 1)
		draw_line(fdf.img, calc_coord(fdf, x, y, calc_height(fdf, x, y)), \
		calc_coord(fdf, x, y + 1, calc_height(fdf, x, y + 1)));
}

void	projection(t_instance fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf.map.height)
	{
		while (x < fdf.map.width)
		{
			draw_grid(fdf, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
}
