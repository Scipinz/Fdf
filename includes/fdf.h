/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 15:12:55 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/07 11:56:48 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_grid
{
	int		size;
	int		x;
	int		y;
	int		z;
	double	height;
}	t_grid;

typedef struct s_map
{
	int	*point;
	int	width;
	int	height;
}	t_map;

typedef struct s_instance
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*str_img;
	t_grid		grid;
}	t_instance;

int		main(int argc, char **argv);
t_map	parse(const char *filepath);
void	error(char *error_msg);
void	init_grid(t_instance *fdf);
void	draw_line(mlx_image_t *img, t_coord start, t_coord end);
void	projection(t_instance fdf);
t_coord	translate_coord(int x, int y);
t_coord	calc_coord(t_instance fdf, int x, int y, int z);

#endif