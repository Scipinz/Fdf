/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:41:22 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/27 12:15:48 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}
