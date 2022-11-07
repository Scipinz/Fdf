/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 12:59:15 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/07 11:47:17 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static t_map	process(char *str_map, int depth)
{
	t_map	map;
	int		i;
	int		num;

	i = 0;
	num = 0;
	map.height = depth;
	map.width = width(str_map);
	map.point = (int *)ft_calloc(map.height * map.width, sizeof(int));
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

	str_map = NULL;
	while (true)
	{
		temp = ft_get_next_line(fd);
		if (temp)
		{
			str_map = ft_strappend(str_map, temp);
			*depth += 1;
		}
		else
			break ;
		free(temp);
	}
	return (str_map);
}

t_map	parse(const char *filepath)
{
	int		fd;
	int		depth;
	char	*str_map;

	depth = 0;
	if (!ft_strnstr(filepath, ".fdf", ft_strlen(filepath)))
		error("Invalid path, path must include \".fdf\"!");
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error("Failed to open file");
	str_map = read_file(fd, &depth);
	if (!str_map)
		error("Failed to read map");
	close(fd);
	return (process(str_map, depth));
}
