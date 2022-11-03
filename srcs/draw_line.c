/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 17:04:40 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/26 14:10:19 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	axis(int start, int end)
{
	if (end < start)
		return (1);
	else
		return (-1);
}

static void	prep(t_coord start, t_coord end, t_coord *diff, t_coord *incr)
{
	diff->x = ft_abs(start.x - end.x);
	diff->y = ft_abs(start.y - end.y);
	incr->x = axis(start.x, end.x);
	incr->y = axis(start.y, end.y);
}

void	draw_line(mlx_image_t *img, t_coord start, t_coord end)
{
	t_coord	diff;
	t_coord	incr;
	t_coord	curr;
	int		boundary;

	prep(start, end, &diff, &incr);
	boundary = 2 * (diff.y - diff.x);
	curr = end;
	while (true)
	{
		if (curr.x < WIDTH && curr.x > 0 && curr.y < HEIGHT && curr.y > 0)
			mlx_put_pixel(img, curr.x, curr.y, 0xFFFFFFFF);
		if (curr.x == start.x && curr.y == start.y)
			break ;
		if (boundary >= 0)
		{
			curr.y += incr.y;
			boundary -= 2 * diff.x;
		}
		if (boundary < 0)
		{
			curr.x += incr.x;
			boundary += 2 * diff.y;
		}
	}
}
