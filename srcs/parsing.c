/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 12:59:15 by kblok         #+#    #+#                 */
/*   Updated: 2022/12/12 15:28:40 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int	width(char *str_map)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (str_map[i] != '\n')
	{
		if (ft_isdigit(str_map[i]))
		{
			width++;
			while (ft_isdigit(str_map[i]))
				i++;
		}
		if (str_map[i] == ' ' || str_map[i] == '-')
			i++;
		if (str_map[i] == ',')
		{
			while (!ft_isspace(str_map[i]))
				i++;
		}
	}
	return (width);
}

static t_map	process(char *str_map, int depth, mlx_t *mlx)
{
	t_map	map;
	int		i;
	int		num;

	i = 0;
	num = 0;
	map.height = depth;
	map.width = width(str_map);
	map.point = (int *)ft_calloc(map.height * map.width, sizeof(int));
	if (!map.point)
		error("Calloc failed", 1, mlx);
	while (str_map[i])
	{
		if (ft_isdigit(str_map[i]) || str_map[i] == '-')
		{
			map.point[num] = ft_atoi(&str_map[i]);
			num++;
		}
		while (!ft_isspace(str_map[i]) && str_map[i])
			i++;
		while (ft_isspace(str_map[i]) && str_map[i])
			i++;
	}
	free (str_map);
	return (map);
}

char	*read_file(int fd, int *depth)
{
	char	*temp;
	char	*str_map;
	char	*append_check;

	str_map = NULL;
	while (true)
	{
		temp = ft_get_next_line(fd);
		if (temp)
		{
			append_check = ft_strappend(str_map, temp);
			if (!append_check)
			{
				free(temp);
				free(str_map);
				return (NULL);
			}
			str_map = append_check;
			*depth += 1;
		}
		else
			break ;
		free(temp);
	}
	return (str_map);
}

static int	file_check(const char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (ft_strcmp(&filename[i], ".fdf") == 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

t_map	parse(const char *filepath, mlx_t *mlx)
{
	int		fd;
	int		depth;
	char	*str_map;

	depth = 0;
	if (!file_check(filepath))
		error("Must provide a \'.fdf\' file!", 1, mlx);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error("Failed to open file", 1, mlx);
	str_map = read_file(fd, &depth);
	if (!str_map)
	{
		close(fd);
		error("Failed to read map", 1, mlx);
	}
	close(fd);
	return (process(str_map, depth, 0));
}
