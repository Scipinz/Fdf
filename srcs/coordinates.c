/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordinates.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 13:51:08 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/18 14:32:05 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso_rot(int *x, int *y)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.5);
	*y = (temp_x + temp_y) * cos(0.5);
}

t_coord	calc_coord(t_instance fdf, int x, int y, int z)
{
	x *= fdf.grid.size;
	y *= fdf.grid.size;
	iso_rot(&x, &y);
	x += WIDTH / 2;
	y += HEIGHT / 2;
	return (translate_coord(x, y));
}
