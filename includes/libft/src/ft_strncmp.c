/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:42:30 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/02 14:58:59 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *str2, size_t num)
{
	size_t	idx;

	idx = 0;
	while (idx < num)
	{
		if (str[idx] == '\0' || str2[idx] == '\0')
			return ((unsigned char)str[idx] - (unsigned char)str2[idx]);
		else if (str[idx] != str2[idx])
		{
			return ((unsigned char)str[idx] - (unsigned char)str2[idx]);
		}
		idx++;
	}
	return (0);
}
